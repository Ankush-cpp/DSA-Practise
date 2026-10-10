#include <iostream>
#include <stack>
using namespace std;

/*
    LeetCode 173 - Binary Search Tree Iterator

    Pattern: BST + Inorder Traversal + Stack

    Time Complexity:
    - next(): O(1) amortized
    - hasNext(): O(1)

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

class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushLeft(TreeNode* root) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        pushLeft(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

int main() {
    /*
            7
           / \
          3   15
             /  \
            9    20

        Iterator output:
        3 7 9 15 20
    */

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator iterator(root);

    cout << "BST Iterator: ";

    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    cout << endl;
    return 0;
}