#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert at tail
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (!head) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Delete a node
void deleteNode(Node*& head, int key) {
    if (!head) return;

    Node* curr = head;
    Node* prev = NULL;

    // If head needs to be deleted
    if (head->data == key) {
        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        if (temp == head) {
            delete head;
            head = NULL;
            return;
        }

        temp->next = head->next;
        head = head->next;
        delete curr;
        return;
    }

    do {
        prev = curr;
        curr = curr->next;

        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
            return;
        }

    } while (curr != head);
}

// Print list
void printList(Node* head) {
    if (!head) return;

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)\n";
}

int main() {
    Node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    printList(head);

    deleteNode(head, 3);

    printList(head);

    return 0;
}