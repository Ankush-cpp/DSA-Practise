#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    LeetCode 783 - Minimum Distance Between BST Nodes

    Approach:
    Inorder traversal of a BST gives values in sorted order.
    Therefore, the minimum difference will always be between
    two consecutive values in the inorder traversal.

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

int previousValue = -1;
int minimumDifference = INT_MAX;

void inorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);

    if (previousValue != -1) {
        minimumDifference = min(minimumDifference,root->val - previousValue);
    }

    previousValue = root->val;

    inorder(root->right);
}

int minDiffInBST(TreeNode* root) {
    previousValue = -1;
    minimumDifference = INT_MAX;

    inorder(root);

    return minimumDifference;
}

int main() {
    /*
            4
           / \
          2   6
         / \
        1   3

        Inorder:
        1 2 3 4 6

        Minimum difference = 1
    */

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << "Minimum Distance: "
         << minDiffInBST(root) << endl;

    return 0;
}