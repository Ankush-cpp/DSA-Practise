
// Problem: Reverse Linked List

// Approach:
// - Use three pointers: prev, curr, forward
// - Traverse the list and reverse links one by one

// Time Complexity: O(n)
// Space Complexity: O(1)

// Source: LeetCode

#include <iostream>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to reverse linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;   // store next node
        curr->next = prev;   // reverse link
        prev = curr;         // move prev forward
        curr = forward;         // move curr forward
    }

    return prev;
}

// Utility function to print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating sample linked list: 1 -> 2 -> 3 -> 4 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}