/*
142. Linked List Cycle II
Level --.Medium
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

TC -->O(N)
sc -->o(1)*/



#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;   // cycle start
            }
        }
        return NULL; // no cycle
    }
};

int main() {
    // Create nodes
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    // Create linked list: 3 -> 2 -> 0 -> -4
    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Create cycle: -4 -> 2
    node4->next = node2;

    Solution sol;
    ListNode* cycleStart = sol.detectCycle(head);

    if (cycleStart != NULL)
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}
