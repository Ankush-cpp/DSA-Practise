#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sum = 0;

    void reverseInorder(TreeNode* root) {
        if (root == nullptr) return;

        reverseInorder(root->right);

        sum += root->val;
        root->val = sum;

        reverseInorder(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        reverseInorder(root);
        return root;
    }
};