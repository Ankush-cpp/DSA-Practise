#include <iostream>
#include <climits>
using namespace std;

/*
    LeetCode 98 - Validate Binary Search Tree

    Approach:
    Check whether every node lies within the valid range
    determined by its ancestors.

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

bool validate(TreeNode* root, long long lower, long long upper) {
    if (root == NULL) {
        return true;
    }

    if (root->val <= lower || root->val >= upper) {
        return false;
    }

    return validate(root->left, lower, root->val) && validate(root->right, root->val, upper);
}

bool isValidBST(TreeNode* root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    /*
            2
           / \
          1   3

        Output: Valid BST
    */

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    if (isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is not a valid BST." << endl;
    }
    return 0;
}