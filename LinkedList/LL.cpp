#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;

    }
};

Node* ConvertArr2LL(vector<int>& arr){
    if(arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0], nullptr);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
//Traversal code
void printLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//search of LL
int CheckIfPresent(Node * head,int val){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        if(temp->data == val) return 1;
        temp = temp->next;
    }
}


Node* removesHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
};

Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next !=NULL){
        temp = temp->next;


    }
    free(temp->next);
    temp->next = NULL;
    return head;
};

Node* removeK(Node* head,int k){
    if(head == NULL)return head;
    if(k == 1){
        Node* temp = head;
        head = head ->next;
        free(temp);
        return head;
    }
    int cnt =0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp !=NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp ;
        temp = temp->next;
    }
    return head;
}

Node* removeEl(Node* head,int el){
    if(head == NULL)return head;
    if(head->data == el){
        Node* temp = head;
        head = head ->next;
        free(temp);
        return head;
    }
    
    Node* temp = head;
    Node* prev = NULL;
    while(temp !=NULL){
        
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp ;
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int>arr = {2,5,7,8};
    Node* head = ConvertArr2LL(arr);
    head = removeEl(head , 8);
   
    printLL(head);

   
}