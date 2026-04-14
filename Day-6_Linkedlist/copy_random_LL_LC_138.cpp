/*
Problem: Copy List with Random Pointer (LC 138)

Approach:
- Use HashMap to store mapping: original node → copied node
- First pass: create all nodes
- Second pass: assign next and random pointers

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if (!head) return NULL;

    unordered_map<Node*, Node*> mp;

    Node* temp = head;

    // Step 1: Create copy nodes
    while (temp) {
        mp[temp] = new Node(temp->val);
        temp = temp->next;
    }

    temp = head;

    // Step 2: Assign next & random
    while (temp) {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }

    return mp[head];
}

// Optional test
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);

    head->random = head->next;
    head->next->random = head;

    Node* copy = copyRandomList(head);

    cout << "Copied head value: " << copy->val << endl;

    return 0;
}