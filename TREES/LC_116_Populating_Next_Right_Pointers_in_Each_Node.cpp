#include <iostream>
using namespace std;

/*
    LeetCode 116 - Populating Next Right Pointers in Each Node

    Pattern: Binary Tree + Level Connections

    Time Complexity: O(n)
    Space Complexity: O(1) auxiliary space
*/

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

Node* connect(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    Node* leftmost = root;

    while (leftmost->left != NULL) {
        Node* current = leftmost;

        while (current != NULL) {
            current->left->next = current->right;

            if (current->next != NULL) {
                current->right->next = current->next->left;
            }

            current = current->next;
        }

        leftmost = leftmost->left;
    }

    return root;
}

int main() {
    /*
              1
             / \
            2   3
           / \ / \
          4  5 6  7

        Connections:
        1 -> NULL
        2 -> 3 -> NULL
        4 -> 5 -> 6 -> 7 -> NULL
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    connect(root);

    Node* level = root;

    while (level != NULL) {
        Node* current = level;

        while (current != NULL) {
            cout << current->val << " -> ";

            if (current->next == NULL) {
                cout << "NULL";
            }

            current = current->next;
        }

        cout << endl;
        level = level->left;
    }

    return 0;
}