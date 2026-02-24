#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* merge_sorted_arrays(ListNode* pt1,ListNode* pt2){
    if(pt1==nullptr) return pt2;
    if(pt2==nullptr) return pt1;
    int i=0;
    ListNode* initial;
    int decider=-1;
    while(pt1!=nullptr && pt2!=nullptr){
        if(pt1->val>pt2->val || (decider==1 && pt1->val==pt2->val)){
            if(i==0) initial=pt2;
            while(pt2->next!=nullptr && pt2->next->val<pt1->val) pt2=pt2->next;
            if(pt2->next==nullptr){
                pt2->next=pt1;
                return initial;
            }
            else{
                ListNode* curr=pt2->next;
                pt2->next=pt1;
                pt2=curr;
                decider=2;
            }
        }
        else{
            if(i==0) initial=pt1;
            while(pt1->next!=nullptr && pt1->next->val<pt2->val) pt1=pt1->next;
            if(pt1->next==nullptr){
                pt1->next=pt2;
                return initial;
            }
            else{
                ListNode* curr=pt1->next;
                pt1->next=pt2;
                pt1=curr;
                decider=1;
            }
        }
        i++;
    }
    return nullptr; 
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size()==0) return nullptr;
    while(lists.size()!=1){
        vector<ListNode*> temp;
        int n=lists.size();
        if(n%2==1){
            for(int i=0;i<n/2;i++){
                ListNode* curr=merge_sorted_arrays(lists[2*i],lists[2*i+1]);
                temp.emplace_back(curr);
            }
            temp.emplace_back(lists[n-1]);
            lists=temp;
        }
        else{
            for(int i=0;i<n/2;i++){
                ListNode* curr=merge_sorted_arrays(lists[2*i],lists[2*i+1]);
                temp.emplace_back(curr);
            }
            lists=temp;
        }
    }
    return lists[0];
}