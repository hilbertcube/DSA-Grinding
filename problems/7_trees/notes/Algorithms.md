# Common Tree Algorithms

## DFS

### Recursive DFS / pre-order, in-order, post-ordeer

```text
function DFS_recursive(node):
  if node is null
    return

  process(node) // preorder
  DFS_recursive(node.left)
  DFS_recursive(node.right)
  return
```

For recursive DFS, simply reorder the functions and we'll have pre-order, in-order, and post-order dfs traversal

### Iterative DFS

```text
function DFS_iterative(node):
  if node is null
    return
  stack = empty stack
  stack.push(root)
  while stack is not empty:
    node = stack.pop() // front
    process(node) // preorder
    if node.left is not null
      stack.push(node.left)
    if node.right is not null
      stack.push(node.right)
  return
```

## BFS / level-order

Since BFS uses a queue, it process nodes level by level

```text
function BFS(node):
  if node is null
    return
  queue = empty queue
  queue.push(node)
  while queue is not empty:
    node = queue.pop() // dequeue
    process(node)
    if node.left is not null
      queue.push(node.left)
    if node.right is not null
      queue.push(node.right)
  return
```


