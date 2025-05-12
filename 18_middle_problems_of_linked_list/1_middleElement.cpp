#include<iostream>
#include<vector>

using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    int count=0;
    ListNode* tempHead=head;
    while(tempHead!=nullptr){
        count++;
        tempHead=tempHead->next;
    }
    for(int i=0;i<count/2;i++){
        head=head->next;
    }
    return head;
}