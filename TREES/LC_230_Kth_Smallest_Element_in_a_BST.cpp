#include <iostream>
using namespace std;

/*
    LeetCode 230 - Kth Smallest Element in a BST

    Approach:
    Inorder traversal of a BST visits nodes in sorted order.

    Keep counting visited nodes during inorder traversal.
    When the count becomes k, the current node is the kth
    smallest element.

    Time Complexity: O(h + k)
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

int count = 0;
int answer = 0;

void inorder(TreeNode* root, int k) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, k);

    if (count == k) {
        return;
    }

    count++;

    if (count == k) {
        answer = root->val;
        return;
    }

    inorder(root->right, k);
}

int kthSmallest(TreeNode* root, int k) {
    count = 0;
    answer = 0;

    inorder(root, k);

    return answer;
}

int main() {
    /*
            3
           / \
          1   4
           \
            2

        Inorder:
        1 2 3 4

        k = 1
        Output: 1
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(1);
    root->right = new TreeNode(4);

    root->left->right = new TreeNode(2);

    int k = 1;

    cout << "Kth Smallest Element: "
         << kthSmallest(root, k) << endl;

    return 0;
}