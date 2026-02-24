#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data,Node* next){
        this->data=data;
        this->next=next;
    }
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
    Node(){
        this->data=-1;
        this->next=nullptr;
    }
    Node* constructLL(vector<int>& arr) {
    int arrSize=arr.size();
    Node* start=new Node(arr[0]);
    Node* startNew=start;
    Node temp=Node();
    if(arrSize==1){
        return start;
    }
    else{
        for(int i=1;i<arrSize;i++){
            start->next=new Node(arr[i]);
            start=start->next;
        }
    }
    return startNew;
}

Node *insertAtEnd(Node *head, int x) {
    Node* tempHead=head;
    if(head==nullptr){
        head=new Node(x);
        return head;
    }
    while(tempHead->next!=nullptr){
        tempHead=tempHead->next;
    }
    tempHead->next=new Node(x);
    return head;
}

//its not a tailnode is gauranteed
void deleteNode(Node* node) {
    node->data=node->next->data;
    node->next=node->next->next;
}

int getCount(struct Node* head) {
    int count=1;
    while(head->next!=nullptr){
        count++;
        head=head->next;
    }
    return count;
}

bool searchKey(int n, Node* head, int key) {
    while(head->next!=nullptr){
        if(head->data==key){
            return true;
        }
    }
    return false;
}

};