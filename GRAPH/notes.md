| 200 | Number of Islands | DFS + Visited Array |

## DFS + Visited Array
- LC 200 – Number of Islands

**Learning**
- Used DFS to explore connected land cells.
- Maintained a separate visited matrix.
- Explored all four directions: Up, Down, Left and Right.
- Every unvisited land cell starts a new island.
- Marked cells as visited to avoid counting the same island again.

**Complexity**
- Time: O(m × n)
- Space: O(m × n)

| LC 200 | O(m × n) | O(m × n) |