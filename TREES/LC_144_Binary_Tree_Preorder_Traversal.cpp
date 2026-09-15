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

void preorder(TreeNode* root, vector<int>& result) {
    if (root == NULL) {
        return;
    }

    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;

    preorder(root, result);

    return result;
}

int main() {
    /*
            1
             \
              2
             /
            3

        Preorder: 1 2 3
    */

    TreeNode* root = new TreeNode(1);

    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = preorderTraversal(root);

    cout << "Preorder Traversal: ";

    for (int value : result) {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}