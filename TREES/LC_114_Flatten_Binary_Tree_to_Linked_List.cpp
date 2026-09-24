#include <iostream>
using namespace std;

/*
    LeetCode 114 - Flatten Binary Tree to Linked List

    Approach:
    Use reverse preorder traversal:
        Right -> Left -> Root

    `endRight` keeps track of the previously processed node.
    Each node is connected to `endRight` using its right pointer,
    while its left pointer is set to NULL.

    Time Complexity: O(n)
    Space Complexity: O(h)
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

TreeNode* endRight = NULL;

void flatten(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    flatten(root->right);
    flatten(root->left);

    root->left = NULL;
    root->right = endRight;

    endRight = root;
}

void printFlattenedTree(TreeNode* root) {
    while (root != NULL) {
        cout << root->val << " -> ";
        root = root->right;
    }

    cout << "NULL" << endl;
}

int main() {
    /*
            1
           / \
          2   5
         / \   \
        3   4   6

        Flattened:
        1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    endRight = NULL;
    flatten(root);

    cout << "Flattened Binary Tree: ";
    printFlattenedTree(root);

    return 0;
}