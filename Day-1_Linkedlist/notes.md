#  Reverse Linked List

##  Problem
Given the head of a singly linked list, reverse the list and return the new head.

---

##  Approach (Iterative)
We use three pointers:

- `prev` → stores previous node  
- `curr` → current node  
- `forward` → stores next node  

### Steps:
1. Traverse the list
2. Reverse the link (`curr->next = prev`)
3. Move all pointers forward

---

##  Complexity
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

##  Key Learning
- Pointer manipulation is the core of linked list problems  
- Always track `forward` before breaking links  

---

##  Sample

**Input:**
1 -> 2 -> 3 -> 4 -> NULL  

**Output:**
4 -> 3 -> 2 -> 1 -> NULL  

---

##  Source
LeetCode - Reverse Linked List