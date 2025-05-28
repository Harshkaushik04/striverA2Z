#include<bits/stdc++.h>
#include "../binary_tree/1_traversal_recursive.cpp"
using namespace std;

int floor(binary_node* node,int key){
    binary_node* current=node;
    int ans=INT32_MIN;
    while(current!=nullptr){
        if(current->content==key) return key;
        if(current->content>ans && current->content<=key) ans=current->content;
        if(current->content>key){
            if(current->left!=nullptr) current=current->left;
            else break;
        }
        else if(current->content<key){
            if(current->right!=nullptr) current=current->right;
            else break;
        }
        if(current->left==nullptr && current->right==nullptr) break;
    }
    return ans;
}

int main(){
    return 0;
}