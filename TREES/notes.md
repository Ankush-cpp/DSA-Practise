# Binary Trees

A collection of classic **Binary Tree** problems solved during my DSA revision.

---

## Problems Solved

| LeetCode | Problem                           | Pattern
|:--------:|:---------------------------------:|:---------------------------------------:|
| 100      | Same Tree                         | Tree Recursion + Structural Comparison  |
| 572      | Subtree of Another Tree           | Tree Recursion + Same Tree              |
| 543      | Diameter of Binary Tree           | Tree Height + Postorder DFS             |
| 102      | Binary Tree Level Order Traversal | BFS + Queue                             |
| 104      | Maximum Depth of Binary Tree      | DFS + Recursion                         |
| 94       | Binary Tree Inorder Traversal     | DFS + Recursion                         |
| 144      | Binary Tree Preorder Traversal    | DFS + Recursion                         |
| 112      | Path Sum                          | DFS + Recursion                         |
| 105      | Construct Binary Tree from........| Recursion + Hash Map                    |
|..........| preorder and Inorder Traversal....|                                         |
| 236      | Lowest Common Ancestor of a Binary tree | DFS + Recursion                   |
| 257      | Binary Tree Paths                 | DFS + Backtracking                      |
| 662      | Maximum Width of Binary Tree      | BFS + Level Indexing                    |
| 114      | Flatten Binary Tree to Linked List| Preorder + In-place Transformation      |
| 98       | Validate Binary Search Tree       | BST + Range Validation                  |
| 108      | Convert Sorted Array to BST       | BST + Divide and Conquer                |
| 783      | Minimum Distance Between BST Nodes| BST + Inorder Traversal                 |
| 230      | Kth Smallest Element in a BST     | BST + Inorder Traversal                 |
| 235      | Lowest Common Ancestor of a Binary Search Tree | BST Property + Iteration   |
| 1008     | Construct Binary Search Tree from Preorder Traversal | BST + Recursion      |
| 99       | Recover Binary Search Tree        | Inorder Traversal + BST Property        |
| 173      | Binary Search Tree Iterator       | BST + Stack + Inorder                   |
| 116      | Populating Next Right Pointers in Each Node | Binary Tree+Level Connections |
| 404      | Sum of Left Leaves                | Binary Tree + Recursion (DFS)           |
| 1302 | Deepest Leaves Sum | BFS + Level Order Traversal |
| 2415 | Reverse Odd Levels of Binary Tree | BFS + Level Order Traversal |

---

# Patterns Covered

## 1. Tree Recursion + Structural Comparison
- LC 100 – Same Tree

**Learning**
- Compare two trees recursively.
- Check both node values.
- Recursively compare the left and right subtrees.
- Handle `NULL` nodes carefully.

---

## 2. Tree Recursion + Same Tree
- LC 572 – Subtree of Another Tree

**Learning**
- Traverse the main tree recursively.
- At every node, check whether the subtree rooted there matches the given subtree.
- Reuse the same-tree comparison concept from LC 100.
- Combine tree traversal with recursive structural comparison.

## 3. Tree Height + Postorder DFS
- LC 543 – Diameter of Binary Tree

**Learning**
- Calculate the height of the left and right subtrees.
- The diameter passing through a node is `leftHeight + rightHeight`.
- Use postorder traversal to calculate subtree heights.
- Maintain the maximum diameter while calculating heights.

## 4. Mirror Recursion
- LC 101 – Symmetric Tree

**Learning**
- Compare the left and right subtrees as mirror images.
- Compare opposite children recursively.
- Left subtree's left child is compared with right subtree's right child.
- Left subtree's right child is compared with right subtree's left child.

## 5. BFS + Queue
- LC 102 – Binary Tree Level Order Traversal

**Learning**
- Use a queue to traverse the tree level by level.
- Process all nodes belonging to the current level together.
- Add the children of each node to the queue for the next level.

---

## 6. DFS + Recursion
- LC 104 – Maximum Depth of Binary Tree

**Learning**
- Recursively calculate the depth of left and right subtrees.
- The depth of a node is one plus the maximum depth of its children.
- Base case: a `NULL` node has depth 0.

## 7. Inorder DFS
- LC 94 – Binary Tree Inorder Traversal

**Learning**
- Traverse the left subtree first.
- Process the current node.
- Traverse the right subtree.
- Follow the `Left → Root → Right` order.

---

## 8. Preorder DFS
- LC 144 – Binary Tree Preorder Traversal

**Learning**
- Process the current node first.
- Traverse the left subtree.
- Traverse the right subtree.
- Follow the `Root → Left → Right` order.

## 9. DFS + Path Sum
- LC 112 – Path Sum

**Learning**
- Traverse the tree recursively.
- Subtract the current node's value from the target sum.
- A valid path must end at a leaf node.
- Return true if either the left or right subtree contains a valid path.

## 10. DFS + Path Tracking
- LC 257 – Binary Tree Paths

**Learning**
- Traverse the tree recursively while maintaining the current path.
- Add the path to the result when a leaf node is reached.
- Explore both left and right subtrees.
- Build the path dynamically using recursion.

## 11. BFS + Level Indexing
- LC 662 – Maximum Width of Binary Tree

## 12. Reverse Preorder + In-place Transformation
- LC 114 – Flatten Binary Tree to Linked List

**Learning**
- Use reverse preorder traversal: `Right → Left → Root`.
- Maintain a pointer to the previously processed node.
- Connect the current node to the previously processed node.
- Set the left pointer to `NULL`.
- Transform the tree in-place without using an additional data structure.

**Learning**
- Use level-order traversal with a queue.
- Assign an index to each node as if the tree were a complete binary tree.
- For each level, calculate width using the first and last node indices.
- Use normalized level indices to avoid unnecessary growth of values.

## 13. BST + Range Validation
- LC 98 – Validate Binary Search Tree

**Learning**
- Every node must satisfy the constraints imposed by its ancestors.
- Maintain a valid range for each node.
- Left subtree values must remain smaller than the current node.
- Right subtree values must remain greater than the current node.

---

## 14. BST + Divide and Conquer
- LC 108 – Convert Sorted Array to Binary Search Tree

**Learning**
- Select the middle element as the root.
- Recursively construct the left and right subtrees.
- Splitting the sorted array around the middle produces a balanced BST.
---
## 15. BST + Inorder Traversal
- LC 783 – Minimum Distance Between BST Nodes

**Learning**
- Inorder traversal of a BST produces values in sorted order.
- Compare each node with the previously visited node.
- The minimum difference is found among consecutive inorder values.
- This allows the answer to be calculated in a single traversal.

## 16. BST + Inorder Traversal
- LC 230 – Kth Smallest Element in a BST

**Learning**
- Inorder traversal of a BST produces values in ascending order.
- Keep track of the number of visited nodes.
- The node visited at position `k` is the kth smallest element.
- The traversal can stop once the kth element is found.

## 17. BST Property + Iteration
- LC 235 – Lowest Common Ancestor of a Binary Search Tree

**Learning**
- Use the ordering property of a BST to decide the direction of traversal.
- If both nodes are smaller than the current node, move left.
- If both nodes are greater than the current node, move right.
- Otherwise, the current node is the Lowest Common Ancestor.
- The BST property allows the search without traversing the entire tree.

## 18. BST + Recursion
- LC 1008 – Construct Binary Search Tree from Preorder Traversal

**Learning**
- The first element of preorder is the root.
- Use the BST property to determine whether the next values belong to the left or right subtree.
- Maintain an upper bound for the current subtree.
- Construct the tree in a single traversal of the preorder array.

## 19. Inorder Traversal + BST Property
- LC 99 – Recover Binary Search Tree

**Learning**
- A valid BST produces sorted values during inorder traversal.
- Detect inversions where the current value is smaller than the previous value.
- Identify the two misplaced nodes.
- Swap their values to restore the BST.

## 20 BST Iterator
- LC 173 – Binary Search Tree Iterator

**Learning**
- Use a stack to simulate inorder traversal iteratively.
- Push the leftmost path of the tree onto the stack.
- `next()` returns the next smallest element in the BST.
- After processing a node, explore the leftmost path of its right subtree.
- Use `hasNext()` to check whether unprocessed nodes remain.
- Maintain traversal state without storing the entire inorder sequence.

---

## 21 Level Connections
- LC 116 – Populating Next Right Pointers in Each Node

**Learning**
- Connect nodes at the same level using their `next` pointers.
- Connect each left child to its right sibling.
- Connect each right child to the left child of the next node at the same level.
- Use existing `next` connections to traverse each level horizontally.
- Process levels using the leftmost node as the starting point.
- Avoid using a queue or any additional data structure.

## 22 Binary Tree + Recursion (DFS)
- LC 404 – Sum of Left Leaves

**Learning**
- Use recursion to traverse the binary tree.
- A left leaf is a node that is the left child of its parent and has no children.
- Check whether the left child is a leaf before adding its value.
- Recursively process both left and right subtrees.
- Return the sum of all left leaf nodes.
- Handle an empty tree by returning `0`.

## BFS + Level Order Traversal

* LC 1302 – Deepest Leaves Sum

**Learning**

* Use a queue to traverse the binary tree level by level.
* Process all nodes at the current level using the queue's size.
* Reset the sum to `0` at the beginning of each level.
* Add each node's value to the current level's sum.
* Push the left and right children into the queue if they exist.
* After BFS finishes, the sum contains only the deepest level's node values.

## BFS + Level Order Traversal

* LC 2415 – Reverse Odd Levels of Binary Tree

**Learning**

* Use a queue to traverse the binary tree level by level.
* Store the nodes of each level in a vector.
* Track the level index, starting from level `0`.
* Reverse node values at odd-numbered levels using two pointers.
* Swap node values instead of changing the tree's structure.
* Return the original root after processing all levels.

# Complexity Summary

| Problem | Time Complexity | Space Complexity |
|---------|-----------------|------------------|
| LC 100  | O(n)            | O(h)             |
| LC 572  | O(n × m)        | O(h)             |
| LC 543  | O(n)            | O(h)             |
| LC 101  | O(n)            | o(h)             |
| LC 102  | O(n)            | O(n)             |
| LC 104  | O(n)            | O(h)             |
| LC 94   | O(n)            | O(h)             |
| LC 144  | O(n)            | O(h)             |
| LC 112  | O(n)            | O(h)             |
| LC 105  | O(n)            | O(n)             |
| LC 236  | O(n)            | O(h)             |
| LC 257  | O(n²)           | O(h)             |
| LC 662  | O(n)            | O(n)             |
| LC 114  | O(n)            | O(h)             |
| LC 98   | O(n)            | O(h)             |
| LC 108  | O(n)            | O(log n)         |
| LC 783  | O(n)            | O(h)             |
| LC 230  | O(h + k)        | O(h)             |
| LC 235  | O(h)            | O(1)             |
| LC 1008 | O(n)            | O(h)             |
| LC 99   | O(n)            | O(h)             |
| LC 173  | O(1) amortized per next() | O(h)   |
| LC 116  | O(n)            | O(1) auxiliary   |
| LC 404  | O(n)            | O(h)             |
| LC 1302 | O(n)            | O(w)             |
| LC 2415 | O(n)            | O(n)             |

Where:
- `n` = number of nodes in the main tree
- `m` = number of nodes in the second tree
- `h` = height of the tree

---

# Key Binary Tree Techniques Learned

- Recursive tree traversal
- Comparing tree structures
- Comparing node values
- Handling `NULL` nodes
- Reusing recursive helper logic
- Subtree identification

---

# Revision Progress

- **Problems Solved:** **2**
- **Unique Patterns Covered:** **2**

## Topics Covered

- Tree Recursion
- Same Tree
- Subtree Checking
- Structural Comparison
- Recursive Traversal

---

> More Binary Tree problems will be added as I continue my DSA revision.