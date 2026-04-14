# Copy List with Random Pointer (LC 138)

## Approach (HashMap)
- Use unordered_map to map original node → copied node
- First pass: create all nodes
- Second pass: assign next and random pointers

## Complexity
- Time: O(n)
- Space: O(n)

## Key Learning
- Deep copy using mapping
- Handling random pointers safely

## Note
Optimal solution exists with O(1) space using node interleaving.