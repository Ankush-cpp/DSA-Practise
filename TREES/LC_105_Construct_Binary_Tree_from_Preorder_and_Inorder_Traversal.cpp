#include <iostream>
#include <vector>
#include <unordered_map>
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

TreeNode* buildTree(
    vector<int>& preorder,
    int preStart,
    int preEnd,
    vector<int>& inorder,
    int inStart,
    int inEnd,
    unordered_map<int, int>& inMap
) {
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }

    int rootValue = preorder[preStart];
    TreeNode* root = new TreeNode(rootValue);

    int rootIndex = inMap[rootValue];
    int leftSize = rootIndex - inStart;

    root->left = buildTree(
        preorder,
        preStart + 1,
        preStart + leftSize,
        inorder,
        inStart,
        rootIndex - 1,
        inMap
    );

    root->right = buildTree(
        preorder,
        preStart + leftSize + 1,
        preEnd,
        inorder,
        rootIndex + 1,
        inEnd,
        inMap
    );

    return root;
}

TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;

    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    return buildTree(
        preorder,
        0,
        preorder.size() - 1,
        inorder,
        0,
        inorder.size() - 1,
        inMap
    );
}

void printPreorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    /*
        Preorder:  [3, 9, 20, 15, 7]
        Inorder:   [9, 3, 15, 20, 7]

        Constructed Tree:

              3
             / \
            9   20
               /  \
              15   7
    */

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = constructTree(preorder, inorder);

    cout << "Preorder of Constructed Tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}