#ifndef GENERAL_HEADERS
#define GENERAL_HEADERS

#include <iostream>
#include <algorithm>
#include <string>

// data structures
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <bitset>
#include <tuple>

#include <utility>
#include <type_traits>
#include <functional>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <climits>
#include <limits>
#include <cassert>
#include <sstream>
#include <cctype>
#include <optional>
#include <cstdint>
#include <cstring>

using namespace std;

// ——— Solution variant selection ———

/**
 * @brief Returns the @p N th function from @p fns, 1-indexed.
 *
 * Called in a constant expression, so the tuple is built and indexed entirely
 * at compile time and nothing survives into the generated code. Prefer the
 * SELECT_IMPL macro over calling this directly.
 *
 * @tparam N    1-based index of the function to return.
 * @tparam Fns  Function pointer types, deduced from @p fns.
 * @param  fns  The candidate functions, in index order.
 * @return The selected function pointer.
 */
template <int N, typename... Fns>
constexpr auto selectImpl(Fns... fns) {
  static_assert(N >= 1 && N <= static_cast<int>(sizeof...(Fns)), "IMPL is out of range for this problem's implementation list");
  return std::get<N - 1>(std::make_tuple(fns...));
}

/**
 * @brief Prints which implementation is active, once, at static-init time.
 *
 * Constructed by SELECT_IMPL. This cannot live inside selectImpl(): that call
 * is a constant expression, and constant evaluation cannot do I/O. Announcing
 * from a separate runtime object keeps the selection itself compile-time.
 */
struct ImplAnnouncer {
  explicit ImplAnnouncer(int n) 
  { 
    cout << "\033[32m==== TESTING IMPLEMENTATION " 
        << n << " ====\033[0m\n"; 
  }
};

/**
 * @def SELECT_IMPL
 * @brief Binds @p name to one of several interchangeable implementations.
 *
 * A problem often carries more than one solution. Name them @c solve1,
 * @c solve2, ... and let this pick the live one, so the tests can call a single
 * stable name and switching is a one-digit edit.
 *
 * Expands to two declarations: a @c constexpr alias resolved at compile time,
 * and a static object that announces the choice at startup. The unused variants
 * cost nothing at runtime, but are still compiled, which stops them rotting.
 *
 * @param n     1-based index of the variant to run. Must be a constant
 *              expression; out of range fails a @c static_assert in
 *              selectImpl() rather than reading past the list.
 * @param name  Identifier the tests call.
 * @param ...   The implementations, in index order.
 *
 * @note Also declares @c name##_announcer in the enclosing scope, so avoid
 *       that identifier yourself.
 * @note The announcement is a separate runtime object by necessity: the
 *       selection is a constant expression, and constant evaluation cannot
 *       perform I/O.
 *
 * @code
 * constexpr int IMPL = 1;
 * SELECT_IMPL(IMPL, invertTree, invertTree1, invertTree2, invertTree3);
 * @endcode
 *
 * @see selectImpl(), ImplAnnouncer
 */
#define SELECT_IMPL(n, name, ...)                   \
  constexpr auto name = selectImpl<n>(__VA_ARGS__); \
  static const ImplAnnouncer name##_announcer { n }

// ——— Sequence containers ———
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '[';
  bool first = true;
  for (auto const &e : v) {
    if (!first)
      os << ", ";
    first = false;
    os << e;
  }
  os << ']';
  return os;
}

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  os << '(' << p.first << ", " << p.second << ')';
  return os;
}

template <typename Tuple, size_t... Is>
void _print_tuple(ostream &os, const Tuple &t, index_sequence<Is...>) {
  ((os << (Is == 0 ? "" : ", ") << get<Is>(t)), ...);
}

template <typename... Args>
ostream &operator<<(ostream &os, const tuple<Args...> &t) {
  os << '(';
  _print_tuple(os, t, index_sequence_for<Args...>{});
  os << ')';
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const deque<T> &d) {
  os << '[';
  bool first = true;
  for (auto const &e : d) {
    if (!first)
      os << ", ";
    first = false;
    os << e;
  }
  os << ']';
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const list<T> &l) {
  os << '[';
  bool first = true;
  for (auto const &e : l) {
    if (!first)
      os << ", ";
    first = false;
    os << e;
  }
  os << ']';
  return os;
}

// ——— Set-like containers ———

template <typename T>
ostream &operator<<(ostream &os, const set<T> &s) {
  os << '{';
  bool first = true;
  for (auto const &e : s) {
    if (!first)
      os << ", ";
    first = false;
    os << e;
  }
  os << '}';
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &s) {
  os << '{';
  bool first = true;
  for (auto const &e : s) {
    if (!first)
      os << ", ";
    first = false;
    os << e;
  }
  os << '}';
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &s) {
  os << '{';
  bool first = true;
  for (auto const &e : s) {
    if (!first)
      os << ", ";
    first = false;
    os << e;
  }
  os << '}';
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &s) {
  os << '{';
  bool first = true;
  for (auto const &e : s) {
    if (!first)
      os << ", ";
    first = false;
    os << e;
  }
  os << '}';
  return os;
}

// ——— Map-like containers ———

template <typename K, typename V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
  os << '{';
  bool first = true;
  for (auto const &kv : m) {
    if (!first)
      os << ", ";
    first = false;
    os << kv.first << ": " << kv.second;
  }
  os << '}';
  return os;
}

template <typename K, typename V>
ostream &operator<<(ostream &os, const multimap<K, V> &m) {
  os << '{';
  bool first = true;
  for (auto const &kv : m) {
    if (!first)
      os << ", ";
    first = false;
    os << kv.first << ": " << kv.second;
  }
  os << '}';
  return os;
}

template <typename K, typename V>
ostream &operator<<(ostream &os, const unordered_map<K, V> &m) {
  os << '{';
  bool first = true;
  for (auto const &kv : m) {
    if (!first)
      os << ", ";
    first = false;
    os << kv.first << ": " << kv.second;
  }
  os << '}';
  return os;
}

template <typename K, typename V>
ostream &operator<<(ostream &os, const unordered_multimap<K, V> &m) {
  os << '{';
  bool first = true;
  for (auto const &kv : m) {
    if (!first)
      os << ", ";
    first = false;
    os << kv.first << ": " << kv.second;
  }
  os << '}';
  return os;
}

// ——— Adapter containers ———

template <typename T, typename Container>
ostream &operator<<(ostream &os, stack<T, Container> s) {
  os << "stack[";
  bool first = true;
  while (!s.empty()) {
    if (!first)
      os << ", ";
    first = false;
    os << s.top();
    s.pop();
  }
  os << ']';
  return os;
}

template <typename T, typename Container>
ostream &operator<<(ostream &os, queue<T, Container> q) {
  os << "queue[";
  bool first = true;
  while (!q.empty()) {
    if (!first)
      os << ", ";
    first = false;
    os << q.front();
    q.pop();
  }
  os << ']';
  return os;
}

template <typename T, typename Container, typename Compare>
ostream &operator<<(ostream &os, priority_queue<T, Container, Compare> pq) {
  os << "priority_queue[";
  bool first = true;
  while (!pq.empty()) {
    if (!first)
      os << ", ";
    first = false;
    os << pq.top();
    pq.pop();
  }
  os << ']';
  return os;
}

void print_bool(bool input) {
  const string GREEN = "\033[32m"; // ANSI code for green
  const string RED = "\033[31m";   // ANSI code for red
  const string RESET = "\033[0m";  // Reset color

  if (input)
    cout << GREEN << "True" << RESET << endl;
  else
    cout << RED << "False" << RESET << endl;
}

#endif