#include <iostream>
using namespace std;

/*
    LeetCode 99 - Recover Binary Search Tree

    Approach:
    - Inorder traversal of a BST should produce values in sorted order.
    - Find the two nodes that violate this ordering.
    - Swap their values to recover the BST.

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

TreeNode* first = NULL;
TreeNode* second = NULL;
TreeNode* previous = NULL;

void inorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);

    if (previous != NULL && previous->val > root->val) {
        if (first == NULL) {
            first = previous;
        }

        second = root;
    }

    previous = root;

    inorder(root->right);
}

void recoverTree(TreeNode* root) {
    first = NULL;
    second = NULL;
    previous = NULL;

    inorder(root);

    if (first != NULL && second != NULL) {
        swap(first->val, second->val);
    }
}

void printInorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /*
            3
           / \
          1   4
             /
            2

        Nodes 2 and 3 are swapped.

        Before recovery:
        Inorder = 1 3 2 4

        After recovery:
        Inorder = 1 2 3 4
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Before Recovery: ";
    printInorder(root);
    cout << endl;

    recoverTree(root);

    cout << "After Recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}