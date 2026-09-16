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

---

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