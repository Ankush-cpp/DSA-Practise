| 200 | Number of Islands | DFS + Visited Array |
| 207 | Course Schedule | DFS + Cycle Detection |

## DFS + Visited Array
- LC 200 – Number of Islands

**Learning**
- Used DFS to explore connected land cells.
- Maintained a separate visited matrix.
- Explored all four directions: Up, Down, Left and Right.
- Every unvisited land cell starts a new island.
- Marked cells as visited to avoid counting the same island again.

DFS + Cycle Detection

LC 207 – Course Schedule

Learning

Represented courses using an adjacency list.

Used DFS to explore prerequisite relationships.

Maintained three states using a visited array:

0 → Unvisited

1 → Currently in DFS path

2 → Completely processed

If DFS encounters a node with state 1, a cycle exists.

If a cycle exists, completing all courses is impossible.

If no cycle exists, all courses can be completed.

**Complexity**
- Time: O(m × n)
- Space: O(m × n)

| LC 200 | O(m × n) | O(m × n) |
| LC 207 | O(V + E) | O(V + E) |