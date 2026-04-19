# Remove Nodes From Linked List (LC 2487)

## Approach
1. Reverse the list
2. Keep track of maximum value so far
3. Remove nodes smaller than max
4. Reverse back

## Complexity
- Time: O(n)
- Space: O(1)

## Key Learning
Reverse + max tracking is a powerful pattern.