# Remove Nth Node From End (LC 19)

## Approach
- Use two pointers (fast & slow)
- Move fast n+1 steps ahead
- Then move both together
- Slow will reach node before target

## Complexity
- Time: O(n)
- Space: O(1)

## Key Learning
Gap technique helps remove node in one pass.