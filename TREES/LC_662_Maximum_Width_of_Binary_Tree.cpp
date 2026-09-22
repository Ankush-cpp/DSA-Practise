#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
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

int widthOfBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});

    unsigned long long maxWidth = 0;

    while (!q.empty()) {
        int size = q.size();

        unsigned long long firstIndex = q.front().second;
        unsigned long long lastIndex = firstIndex;

        for (int i = 0; i < size; i++) {
            TreeNode* current = q.front().first;
            unsigned long long index = q.front().second;

            q.pop();

            lastIndex = index;

            if (current->left != NULL) {
                q.push({
                    current->left,
                    2 * index + 1
                });
            }

            if (current->right != NULL) {
                q.push({
                    current->right,
                    2 * index + 2
                });
            }
        }
        maxWidth = max(maxWidth, lastIndex - firstIndex + 1);
    } return maxWidth;
}

int main() {
    /*
              1
             / \
            3   2
           /     \
          5       9

        Maximum Width = 4

        The positions at the last level are:
        5 _ _ 9
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);

    cout << "Maximum Width: "
         << widthOfBinaryTree(root) << endl;

    return 0;
}