# Tree Theories

Definitions, properties, and the mental models behind the tree problems in this
folder. Traversal pseudocode lives in [Algorithms.md](Algorithms.md); this file
is the *why* behind it.

## 1. Definition

A **tree** is a connected, acyclic, undirected graph. A **rooted tree** fixes one
vertex as the root, which orients every edge away from it and gives each non-root
node exactly one parent.

Three equivalent characterizations for a graph $G = (V, E)$ with $n = |V|$:

- $G$ is connected and acyclic
- $G$ is connected and $|E| = n - 1$
- there is exactly one simple path between any two vertices

So a tree on $n$ nodes always has

$$|E| = n - 1$$

which is why almost every whole-tree traversal is $O(n)$: you touch each node
once and each edge at most twice.

A **binary tree** is a rooted tree where every node has at most two children, and
the children are *ordered*: `left` and `right` are distinguishable even when one
is null. That ordering is what makes `[1, 2, null]` and `[1, null, 2]` different
trees.

## 2. Terminology

| Term | Meaning |
| --- | --- |
| root | the single node with no parent |
| leaf (external) | node with no children |
| internal node | node with at least one child |
| sibling | nodes sharing a parent |
| ancestor / descendant | node on the path to the root / in the subtree |
| subtree of $v$ | $v$ together with all its descendants |
| degree of $v$ | number of children of $v$ ($\le 2$ for binary trees) |
| level | set of all nodes at the same depth |
| width of a level | number of nodes on that level |
| path length | number of **edges** on the path, not nodes |

### Depth vs height

For a node $v$:

- $\operatorname{depth}(v) = \text{edges from the root down to } v, \qquad \operatorname{depth}(\text{root}) = 0$

- $\operatorname{height}(v) = \text{edges on the longest path from } v \text{ down to a leaf}, \qquad \operatorname{height}(\text{leaf}) = 0$

The height of the tree is $h = \operatorname{height}(\text{root})$. The empty tree
is conventionally $h = -1$, which is exactly what makes the recursion

$$\operatorname{height}(v) = 1 + \max\bigl(\operatorname{height}(v.\text{left}),\ \operatorname{height}(v.\text{right})\bigr)$$

work with no special case for a leaf.

> **Careful:** LeetCode's *maximum depth* counts **nodes**, not edges, so its
> answer is $h + 1$ and the empty tree returns $0$. `02_maximum-depth-of-binary-tree`
> uses the node convention; `03_diameter-of-binary-tree` uses the edge
> convention. Pick one per problem and write it in a comment, because mixing them is the
> single most common off-by-one in this whole category.

## 3. Counting properties

Let $n$ be the number of nodes and $h$ the height.

- **Nodes per level.** Level $d$ holds at most $2^d$ nodes, so

$$n \le \sum_{d=0}^{h} 2^{d} = 2^{h+1} - 1$$

- **Height bounds.** Rearranging the above, and noting a chain is the worst case:

  $$\lfloor \log_2 n \rfloor \le h \le n - 1$$

  The lower bound is a *perfectly balanced* tree, the upper bound a *degenerate*
  one (a linked list). Every "is this $O(\log n)$ or $O(n)$?" question about trees
  reduces to which end of this range you are on.

- **Leaves vs. degree-2 nodes.** In any binary tree, with $n_0$ leaves and $n_2$
nodes of degree 2:

$$n_0 = n_2 + 1$$

- **Shape count.** The number of structurally distinct binary trees on $n$ nodes is the Catalan number

  $$C_n = \frac{1}{n+1}\binom{2n}{n}$$

  which grows like $4^n / (n^{3/2}\sqrt{\pi})$, therefore brute-forcing over shapes is never
  the plan.

## 4. Shapes of binary trees

| Shape | Condition | Consequence |
| --- | --- | --- |
| **Full** (strict) | every node has 0 or 2 children | $n$ is odd, $n_0 = n_2 + 1$ |
| **Complete** | all levels full except possibly the last, which fills left to right | $h = \lfloor \log_2 n \rfloor$; array-representable with no gaps |
| **Perfect** | all internal nodes have 2 children and all leaves are on the same level | $n = 2^{h+1} - 1$, leaves $= 2^h$, internal $= 2^h - 1$ |
| **Balanced** | heights of the two subtrees of *every* node differ by $\le 1$ | $h = O(\log n)$ |
| **Degenerate** | every node has $\le 1$ child | $h = n - 1$, behaves like a list |

Perfect $\Rightarrow$ complete $\Rightarrow$ balanced. The converses are false.

Note that "balanced" is a condition on *every* node, not just the root. That's
why `04_balanced-binary-tree` has to check the whole tree, and why the clean
solution returns height and the balanced-flag together from one post-order pass
instead of calling a height helper from inside a height helper ($O(n)$ vs
$O(n \log n)$).

## 5. Representations

**Linked nodes**, what this repo uses (`include/tree_helpers.h`):

```cpp
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};
```

**Implicit array**, only sound for *complete* trees (this is how a binary heap
is stored). With 0-based indexing:

$$\text{left}(i) = 2i + 1, \qquad \text{right}(i) = 2i + 2, \qquad \text{parent}(i) = \left\lfloor \frac{i-1}{2} \right\rfloor$$

Zero pointer overhead and cache-friendly, but a sparse tree wastes $O(2^h)$ slots.

**Level-order list with nulls**, the LeetCode serialization, e.g.
`{3, 9, 20, null, null, 15, 7}`. It is a BFS emission where missing children are
explicit, and it is what `buildTreeFromLevelOrder` consumes. Unlike the implicit
array it does *not* reserve slots for the children of a null, so index arithmetic
does not apply to it.

**Parent array**, one `parent[i]` per node; good for union-find and upward walks,
useless for downward traversal.

## 6. Traversals in theory

Four canonical orders. The first three are DFS and differ only in *when* the node
is visited relative to its subtrees:

| Order | Visit sequence | Typical use |
| --- | --- | --- |
| Pre-order | node, left, right | copy/serialize a tree, top-down state |
| In-order | left, node, right | **sorted output on a BST** |
| Post-order | left, right, node | free/delete, any bottom-up aggregate |
| Level-order (BFS) | by increasing depth | shortest depth, per-level answers |

All four are $O(n)$ time. Space differs: DFS costs $O(h)$ stack, BFS costs
$O(w)$ where $w$ is the maximum level width, and in a complete tree
$w = \lceil n/2 \rceil$, since the bottom level holds about half the nodes. So DFS is
the cheaper default, and BFS earns its memory only when the question is about
levels or about the shallowest anything.

### Reconstruction

Which pairs of traversals determine a tree uniquely (values distinct)?

- pre-order + in-order $\Rightarrow$ **unique** (`13_construct-binary-tree-...`)
- post-order + in-order $\Rightarrow$ **unique**
- pre-order + post-order $\Rightarrow$ **ambiguous** in general, unique only if the tree is full

The reason: in-order tells you how a subtree splits into left/right around the
root; pre/post-order tell you which node is the root. Without in-order you cannot
tell an only-child apart from a left-child vs a right-child.

A single traversal *is* enough if nulls are recorded. That is why
`toPreorderString` uses `#` for null and why serialization
(`15_serialize-and-deserialize-binary-tree`) works with one pre-order pass.

## 7. Binary search trees

A BST maintains, for every node $v$:

$$\max(\text{keys in } v.\text{left}) < v.\text{val} < \min(\text{keys in } v.\text{right})$$

This is a **global** invariant, not a local parent-child comparison. Checking only
`left.val < val < right.val` at each node is the classic wrong answer to
`11_validate-binary-search-tree`; the two correct approaches are:

1. carry an open interval $(\text{low}, \text{high})$ down the recursion and
   narrow it at each step, or
2. do an in-order walk and assert the sequence is strictly increasing.

**In-order = sorted** is the property nearly every BST problem leans on: it makes
`12_kth-smallest-element-in-a-bst` an in-order walk stopped after $k$ visits.

### Operations

Search, insert, and delete all walk one root-to-leaf path, so they cost $O(h)$:

$$O(\log n) \text{ if balanced}, \qquad O(n) \text{ if degenerate}$$

Inserting sorted data into an unbalanced BST produces exactly the degenerate case.
Under random insertion order the expected height is $\Theta(\log n)$
(about $4.31 \log_2 n$), but expectation is not a guarantee, hence self-balancing
trees.

**Deletion** has three cases: a leaf is removed outright; a node with one child is
replaced by that child; a node with two children is replaced by its in-order
**successor** (leftmost node of the right subtree) or predecessor, which is then
deleted recursively from that subtree.

**LCA in a BST** is cheap precisely because of the ordering: descend from the root
and the first node whose value lies between the two targets is their lowest common
ancestor ($O(h)$, no subtree search, as in `07_lowest-common-ancestor-...`). In a plain
binary tree there is no such shortcut and LCA becomes an $O(n)$ post-order that
returns "found p", "found q", or "found both here".

## 8. Self-balancing trees and relatives

You rarely implement these in interviews, but you are expected to know the bounds.

| Structure | Invariant | Height bound |
| --- | --- | --- |
| **AVL** | balance factor $\lvert h_L - h_R \rvert \le 1$ at every node | $h < 1.4405\log_2(n+2) - 0.3277$ |
| **Red-black** | no two consecutive reds; equal black-height on all paths | $h \le 2\log_2(n+1)$ |
| **B-tree** (order $m$) | all leaves at same depth, $\lceil m/2 \rceil$ to $m$ children | $h = O(\log_m n)$ |
| **Binary heap** | parent $\le$ (or $\ge$) both children; complete shape | $h = \lfloor \log_2 n \rfloor$ |
| **Trie** | edges labelled by characters | depth = key length $L$ |

AVL's bound comes from the minimum node count at height $h$, which follows a
Fibonacci-like recurrence:

$$N(h) = N(h-1) + N(h-2) + 1, \qquad N(0) = 1,\ N(1) = 2$$

AVL is more rigidly balanced (faster lookups), red-black rebalances less on
writes (cheaper inserts/deletes), which is why `std::map` and `std::set` are
red-black trees.

A heap is *not* a BST: it only orders parent against child, so it answers "min/max"
in $O(1)$ but cannot search for an arbitrary key faster than $O(n)$.

A trie's cost depends on key length, not on $n$: lookup is $O(L)$ with
$O(\Sigma \cdot \text{total chars})$ space for alphabet $\Sigma$.

## 9. Complexity summary

$n$ = nodes, $h$ = height, $w$ = maximum level width.

| Operation | Time | Space |
| --- | --- | --- |
| Any full traversal | $O(n)$ | $O(h)$ DFS / $O(w)$ BFS |
| Height, diameter, sum, count | $O(n)$ | $O(h)$ |
| BST search / insert / delete | $O(h)$ | $O(h)$ recursive, $O(1)$ iterative |
| BST in-order (sorted output) | $O(n)$ | $O(h)$ |
| Balanced BST search | $O(\log n)$ | $O(\log n)$ |
| Heap push / pop | $O(\log n)$ | $O(1)$ |
| Build heap from array | $O(n)$ | $O(1)$ |
| `isSubtree` (naive) | $O(n \cdot m)$ | $O(h)$ |
| `isSubtree` (serialize + substring) | $O(n + m)$ | $O(n + m)$ |

Worst case $h = n$, best case $h = \lfloor \log_2 n \rfloor$. Quoting $O(\log n)$
for an *unbalanced* tree is wrong; quote $O(h)$ and then state the assumption.

## 10. Why tree recursion is linear

Single-pass tree recursions satisfy

$$T(n) = T(k) + T(n - 1 - k) + O(1)$$

for a root whose left subtree has $k$ nodes. Regardless of how lopsided the split
is, the recursion tree has exactly one frame per node, so $T(n) = O(n)$. The split
does not affect *time*; it affects *stack depth*, which is $O(h)$.

The cost blows up only when work at a node is not $O(1)$. Calling an $O(n)$
height helper from every node gives

$$T(n) = 2T(n/2) + O(n) = O(n \log n)$$

in the balanced case and $O(n^2)$ when degenerate. Recognizing this is the whole
trick behind the linear solutions to `04_balanced-binary-tree` and
`03_diameter-of-binary-tree`.

## 11. The two recursion shapes

Almost every problem here is one of these.

**Top-down (pre-order): pass state *down*.** The parent hands the child everything
it needs; the answer is collected at the leaves or in an accumulator.

$$f(v, \text{state}) \rightarrow f(v.\text{left}, \text{state}'),\ f(v.\text{right}, \text{state}')$$

Used by `10_count-good-nodes-in-binary-tree` (carry the max seen so far) and
`11_validate-binary-search-tree` (carry the valid interval).

**Bottom-up (post-order): return information *up*.** Each call returns a summary
of its subtree and the parent combines the two summaries in $O(1)$.

$$f(v) = \text{combine}\bigl(f(v.\text{left}),\ f(v.\text{right}),\ v\bigr)$$

Used by height, `04_balanced-binary-tree`, and LCA.

**The hybrid: local return + global answer.** When the answer can live at a node
that is not the root, the recursion returns the value the *parent* needs while a
reference/member variable absorbs the best answer seen anywhere. This is the
pattern in `03_diameter-of-binary-tree`:

$$\text{best} \leftarrow \max(\text{best},\ h_L + h_R), \qquad \text{return } 1 + \max(h_L, h_R)$$

The returned value and the recorded value are deliberately different, because a path
turning at $v$ cannot be extended through $v$'s parent. Same skeleton in
`14_binary-tree-maximum-path-sum`, with the extra rule that a negative branch is
clamped to $0$ (drop it rather than extend it).

## 12. Checklist for tree problems

1. **Null root.** Every recursion needs the base case; most bugs are there.
2. **Edges or nodes?** Fix the counting convention before writing the return.
3. **Which order?** Need child results $\Rightarrow$ post-order. Need parent
   context $\Rightarrow$ pre-order. Need sorted BST keys $\Rightarrow$ in-order.
   Need levels or shallowest $\Rightarrow$ BFS.
4. **BST or plain?** If BST, the ordering usually turns an $O(n)$ scan into
   $O(h)$.
5. **Is the answer allowed to skip the root?** If yes, use the local-return +
   global-answer hybrid.
6. **State the height assumption** when giving complexity: $O(h)$, which is
   $O(\log n)$ only if balanced.
7. **Single node, two nodes, straight-line chain:** the three test shapes that
   catch nearly every off-by-one.
