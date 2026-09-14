#include <iostream>
#include <vector>
#include <queue>
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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> answer;

    if (root == NULL) {
        return answer;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++) {
            TreeNode* current = q.front();
            q.pop();
            level.push_back(current->val);
            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
        answer.push_back(level);
    } return answer;
}

int main() {
    /*
            3
           / \
          9   20
             /  \
            15   7

        Output:
        3
        9 20
        15 7
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> result = levelOrder(root);
    cout << "Level Order Traversal:" << endl;
    for (vector<int> level : result) {
        for (int value : level) {
            cout << value << " ";
        }
        cout << endl;
    } return 0;
}