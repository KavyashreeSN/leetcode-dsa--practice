/*148.Sort List

Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []*/



#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    
    // Find middle of linked list
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;  // ensures first middle in even length
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if(list1) temp->next = list1;
        else temp->next = list2;

        return dummyNode->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoLists(left, right);
    }
};

// Function to insert node at end
void insertNode(ListNode* &head, int val){
    if(head == NULL){
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}

// Function to print linked list
void printList(ListNode* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = NULL;

    // Example input: 4 -> 2 -> 1 -> 3
    insertNode(head, 4);
    insertNode(head, 2);
    insertNode(head, 1);
    insertNode(head, 3);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}