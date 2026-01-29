/*234.Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.*/


#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* reverseLinkedList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseLinkedList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // find middle
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        ListNode* newHead = reverseLinkedList(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;

        // compare
        while (second != NULL) {
            if (first->val != second->val) {
                reverseLinkedList(newHead); // restore
                return false;
            }
            first = first->next;
            second = second->next;
        }

        reverseLinkedList(newHead); 
        return true;
    }
};


// helper function to insert at end
ListNode* insertEnd(ListNode* head, int val) {
    if (!head) return new ListNode(val);
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new ListNode(val);
    return head;
}

// helper function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = NULL;

    // Example palindrome list: 1 2 3 2 1
    int arr[] = {1, 2, 3, 2, 1};
    for (int x : arr)
        head = insertEnd(head, x);

    cout << "Linked List: ";
    printList(head);

    Solution obj;
    bool ans = obj.isPalindrome(head);

    if (ans)
        cout << "It is a Palindrome\n";
    else
        cout << "Not a Palindrome\n";

    cout << "List after check (restored): ";
    printList(head);

    return 0;
}
