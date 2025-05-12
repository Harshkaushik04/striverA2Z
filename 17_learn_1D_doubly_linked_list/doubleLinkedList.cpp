#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data=0;
        this->prev=nullptr;
        this->next=nullptr;
    }

    Node(int data){
        this->data=data;
        this->prev=nullptr;
        this->next=nullptr;
    }
};

Node* constructDLL(vector<int>& arr) {
    int arrSize=arr.size();
    Node* head=new Node(arr[0]);
    Node* copyHead=head;
    Node* temp;
    for(int i=1;i<arrSize;i++){
      head->next=new Node(arr[i]); 
      head->next->prev=head;
      head=head->next; 
    }
    return copyHead;
}

Node *addNode(Node *head, int pos, int data) {
    Node* temp=head;
    Node* temp2;
    for(int i=0;i<pos;i++){
        temp=temp->next;
    }
    if(temp->next==nullptr){
        temp->next=new Node(data);
        temp->next->prev=temp;
    }
    else{
        temp2=temp->next;
        temp->next=new Node(data);
        temp->next->prev=temp;
        temp->next->next=temp2;
        temp2->prev=temp->next;
    }
    return head;
}

Node* deleteNode(Node* head, int x) {
    Node* temp;
    Node* temp2;
    if(x==1){
        if(head->next==nullptr){
            return nullptr;
        }
        // head->next!=nullptr
        head=head->next;
        head->prev->next=nullptr;
        head->prev=nullptr;
        return head;
    }
    // if x!=1
    temp=head;
    for(int i=0;i<x-1;i++){
        temp=temp->next;
    }
    if(temp->next!=nullptr){
        temp2=temp->prev;
        temp->prev->next=temp->next;
        temp->next->prev=temp2;
        temp->next=nullptr;
        temp->prev=nullptr;
        return head;
    }
    else{
        temp2=temp->prev;
        temp->prev=nullptr;
        temp2->next=nullptr;
        return head;
    }
    return head;
}

Node* reverseDLL(Node* head) {
    Node* temp1;
    Node* temp2;
    Node* temp;
    temp=head;
    while(temp->next!=nullptr){
        temp1=temp->prev;
        temp2=temp->next;
        temp->prev=temp2;
        temp->next=temp1;
        temp=temp2;
    }
    return temp;
}