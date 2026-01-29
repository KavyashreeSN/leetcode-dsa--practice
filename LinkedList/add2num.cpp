/*2.Add 2 Numbers 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 TC -->O(max(n,m))
 SC-->O(max(n,m))*/



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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        int carry = 0;

        while (t1 != NULL || t2 != NULL) {
            int sum = carry;

            if (t1) sum += t1->val;
            if (t2) sum += t2->val;

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            curr->next = newNode;
            curr = curr->next;

            if (t1) t1 = t1->next;
            if (t2) t2 = t2->next;
        }

        if (carry) {
            curr->next = new ListNode(carry);
        }

        return dummyNode->next;
    }
};

// helper: insert at end
ListNode* insertEnd(ListNode* head, int val) {
    if (!head) return new ListNode(val);
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new ListNode(val);
    return head;
}

// helper: print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;

    // number 342 → stored as 2->4->3
    int a[] = {2,4,3};
    for (int x : a) l1 = insertEnd(l1, x);

    // number 465 → stored as 5->6->4
    int b[] = {5,6,4};
    for (int x : b) l2 = insertEnd(l2, x);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    Solution obj;
    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "Sum List: ";
    printList(result);

    return 0;
}
