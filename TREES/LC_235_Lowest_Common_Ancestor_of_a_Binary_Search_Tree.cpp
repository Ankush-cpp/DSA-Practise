#include <iostream>
using namespace std;

/*
    LeetCode 235 - Lowest Common Ancestor of a Binary Search Tree

    Approach:
    Use the BST property:
    - If both p and q are smaller than root, move left.
    - If both p and q are greater than root, move right.
    - Otherwise, the current root is their Lowest Common Ancestor.

    Time Complexity: O(h)
    Space Complexity: O(1)
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* lowestCommonAncestor(
    TreeNode* root,
    TreeNode* p,
    TreeNode* q
) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }
        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }
        else {
            return root;
        }
    }

    return NULL;
}

int main() {
    /*
              6
             / \
            2   8
           / \ / \
          0  4 7  9
            / \
           3   5

        p = 2
        q = 8

        LCA = 6
    */

    TreeNode* root = new TreeNode(6);

    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* answer = lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor: "
         << answer->val << endl;

    return 0;
}