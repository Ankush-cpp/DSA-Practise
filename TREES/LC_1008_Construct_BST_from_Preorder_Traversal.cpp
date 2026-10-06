#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 1008 - Construct Binary Search Tree from Preorder Traversal

    Approach:
    In preorder traversal, the first element is always the root.
    Recursively construct the left and right subtrees using the BST property.

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

TreeNode* buildBST(
    vector<int>& preorder,
    int& index,
    int upperBound
) {
    if (index == preorder.size() ||
        preorder[index] > upperBound) {
        return NULL;
    }
    int rootValue = preorder[index++];
    TreeNode* root = new TreeNode(rootValue);
    root->left = buildBST(
        preorder,
        index,
        rootValue
    );
    root->right = buildBST(
        preorder,
        index,
        upperBound
    );
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int index = 0;
    return buildBST(
        preorder,
        index,
        INT_MAX
    );
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
        Preorder:
        [8, 5, 1, 7, 10, 12]
        Constructed BST:

              8
             / \
            5   10
           / \    \
          1   7    12

        Inorder:
        1 5 7 8 10 12
    */

    vector<int> preorder = {
        8, 5, 1, 7, 10, 12
    };
    TreeNode* root = bstFromPreorder(preorder);
    cout << "Inorder Traversal of Constructed BST: ";
    inorder(root);
    cout << endl;
    return 0;
}