#include <iostream>
using namespace std;

// Node class
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

// Solution class
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

// Function to insert node at end
void insertAtEnd(ListNode* &head, int data) {
    ListNode* newNode = new ListNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to print list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode* head = NULL;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertAtEnd(head, x);
    }

    cout << "\nOriginal Linked List: ";
    printList(head);

    Solution obj;
    head = obj.reverseList(head);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}