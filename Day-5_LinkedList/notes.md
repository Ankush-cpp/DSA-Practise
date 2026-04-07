# Reverse Linked List II (LC 92)

## Approach
- Use dummy node
- Move pointer to node before 'left'
- Reverse sublist using head insertion technique

## Steps
1. Reach node before left
2. Reverse nodes between left and right
3. Reconnect the list

## Complexity
- Time: O(n)
- Space: O(1)

## Key Learning
- Partial reversal of linked list
- Careful pointer manipulation