/*Length of loop in LL

Given the head of a singly linked list, find the length of the loop in the linked list if it exists. Return the length of the loop if it exists; otherwise, return 0.

A loop exists in a linked list if some node in the list can be reached again by continuously following the next pointer. Internally, pos is used to denote the index (0-based) of the node from where the loop starts.
Note that pos is not passed as a parameter.*/

#include <iostream>
using namespace std;

/*
Definition of singly linked list
*/
struct ListNode {
    int val;
    ListNode *next;

    ListNode() {
        val = 0;
        next = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1) {
        val = data1;
        next = next1;
    }
};

class Solution {
    int findLength(ListNode* slow, ListNode* fast) {
        int cnt = 1;
        fast = fast->next;

        while (slow != fast) {
            cnt++;
            fast = fast->next;
        }
        return cnt;
    }

public:
    int findLengthOfLoop(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return findLength(slow, fast);
        }
        return 0;
    }
};

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next;

    Solution obj;
    int loopLength = obj.findLengthOfLoop(head);

    cout << "Length of loop: " << loopLength << endl;

    return 0;
}
