# Next Greater Element I (LC 496)

## Approach
- Use a monotonic decreasing stack
- Traverse nums2:
  - If current > stack top → assign next greater
- Store mapping in hashmap

## Complexity
- Time: O(n)
- Space: O(n)

## Key Learning
Monotonic stack helps solve "next greater/smaller" problems efficiently.