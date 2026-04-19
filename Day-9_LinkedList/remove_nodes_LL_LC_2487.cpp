#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    while (head) {
        ListNode* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

ListNode* removeNodes(ListNode* head) {
    // Reverse list
    head = reverse(head);

    int maxVal = head->val;
    ListNode* curr = head;

    while (curr && curr->next) {
        if (curr->next->val < maxVal) {
            ListNode* del = curr->next;
            curr->next = curr->next->next;
            delete del;
        } else {
            curr = curr->next;
            maxVal = curr->val;
        }
    }

    // Reverse back
    return reverse(head);
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // 5->2->13->3->8
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    head = removeNodes(head);
    printList(head);

    return 0;
}