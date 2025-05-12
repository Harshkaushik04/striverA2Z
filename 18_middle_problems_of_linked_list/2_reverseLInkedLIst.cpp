#include<iostream>

using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseList(ListNode* head) {
    ListNode* prevptr=nullptr;
    ListNode* nextptr=nullptr;
    ListNode* temp=head;
    ListNode* current=head;
    while(temp!=nullptr){
        nextptr=temp->next;
        current->next=prevptr;
    }
}