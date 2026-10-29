#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> nodes;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                nodes.push_back(node);

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            if (level % 2 == 1) {
                int left = 0;
                int right = nodes.size() - 1;

                while (left < right) {
                    swap(nodes[left]->val, nodes[right]->val);
                    left++;
                    right--;
                }
            }

            level++;
        }

        return root;
    }
};

void printLevelOrder(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    /*
              2
             / \
            3   5
           / \ / \
          8  13 21 34

       Expected level order after reversal:
       2 5 3 8 13 21 34
    */

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(13);
    root->right->left = new TreeNode(21);
    root->right->right = new TreeNode(34);

    Solution sol;
    root = sol.reverseOddLevels(root);

    cout << "Level Order: ";
    printLevelOrder(root);

    return 0;
}