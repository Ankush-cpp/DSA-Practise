#include <iostream>
#include <vector>
#include <string>
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

void findPaths(
    TreeNode* root,
    string currentPath,
    vector<string>& result
) {
    if (root == NULL) {
        return;
    }

    if (currentPath.empty()) {
        currentPath = to_string(root->val);
    } else {
        currentPath += "->" + to_string(root->val);
    }

    if (root->left == NULL && root->right == NULL) {
        result.push_back(currentPath);
        return;
    }

    findPaths(root->left, currentPath, result);
    findPaths(root->right, currentPath, result);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;

    findPaths(root, "", result);

    return result;
}

int main() {
    /*
            1
           / \
          2   3
           \
            5

        Output:
        1->2->5
        1->3
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);

    vector<string> result = binaryTreePaths(root);

    cout << "Binary Tree Paths:" << endl;

    for (string path : result) {
        cout << path << endl;
    }

    return 0;
}