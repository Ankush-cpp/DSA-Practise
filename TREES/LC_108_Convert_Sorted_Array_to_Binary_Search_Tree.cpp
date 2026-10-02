#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 108 - Convert Sorted Array to Binary Search Tree

    Approach:
    - Choose the middle element as the root.
    - Recursively build the left subtree from the left half.
    - Recursively build the right subtree from the right half.

    Choosing the middle element keeps the BST height balanced.

    Time Complexity: O(n)
    Space Complexity: O(log n)
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

TreeNode* buildBST(vector<int>& nums, int left, int right) {
    if (left > right) {
        return NULL;
    }

    int mid = left + (right - left) / 2;

    TreeNode* root = new TreeNode(nums[mid]);

    root->left = buildBST(nums, left, mid - 1);
    root->right = buildBST(nums, mid + 1, right);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return buildBST(nums, 0, nums.size() - 1);
}

void inorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
        Sorted Array:
        [-10, -3, 0, 5, 9]

        One possible balanced BST:

                0
               / \
             -3   9
             /   /
           -10   5
    */

    vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode* root = sortedArrayToBST(nums);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}