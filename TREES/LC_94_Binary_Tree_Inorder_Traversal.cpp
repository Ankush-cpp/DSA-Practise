#include <iostream>
#include <vector>
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

void inorder(TreeNode* root, vector<int>& result) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;

    inorder(root, result);

    return result;
}

int main() {
    /*
            1
             \
              2
             /
            3

        Inorder: 1 3 2
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> result = inorderTraversal(root);
    cout << "Inorder Traversal: ";
    for (int value : result) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}