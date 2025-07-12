#include<bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

int ceil(TreeNode* node,int key){
    TreeNode* current=node;
    int ans=INT32_MAX;
    if(current->content>=key){
        ans=current->content;
    }
    while(current!=nullptr){
        if(current->content==key) return key;
        if(current->content>key){
            if(current->left!=nullptr) current=current->left;
            else break;
        }
        else if(current->content<key){
            if(current->right!=nullptr) current=current->right;
            else break;
        }
        if(current->content>=key && current->content<ans){
            ans=current->content;
        }
        if(current->left==nullptr && current->right==nullptr){
            break;
        }
    }
    return ans;
}
