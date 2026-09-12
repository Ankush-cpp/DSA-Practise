# Binary Trees

A collection of classic **Binary Tree** problems solved during my DSA revision.

---

## Problems Solved

| LeetCode | Problem                 | Pattern
|:--------:|:-----------------------:|:---------------------------------------:|
| 100      | Same Tree               | Tree Recursion + Structural Comparison  |
| 572      | Subtree of Another Tree | Tree Recursion + Same Tree              |
| 543      | Diameter of Binary Tree | Tree Height + Postorder DFS             |

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

---

# Complexity Summary

| Problem | Time Complexity | Space Complexity |
|---------|-----------------|------------------|
| LC 100  | O(n)            | O(h)             |
| LC 572  | O(n × m)        | O(h)             |
| LC 543  | O(n)            | O(h)             |
| LC 101  | O(n)            | o(h)             |

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