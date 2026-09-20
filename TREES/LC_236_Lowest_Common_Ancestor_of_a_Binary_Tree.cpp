#include <iostream>
using namespace std;

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
    if (root == NULL || root == p || root == q) {
        return root;
    }

    TreeNode* leftResult = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightResult = lowestCommonAncestor(root->right, p, q);

    if (leftResult != NULL && rightResult != NULL) {
        return root;
    }

    if (leftResult != NULL) {
        return leftResult;
    }

    return rightResult;
}

int main() {
    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4

        p = 5
        q = 1

        LCA = 3
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* answer = lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor: "
         << answer->val << endl;

    return 0;
}