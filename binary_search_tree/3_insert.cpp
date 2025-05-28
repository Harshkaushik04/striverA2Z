#include<bits/stdc++.h>
#include "../binary_tree/1_traversal_recursive.cpp"
using namespace std;

binary_node* insertNode(binary_node* node,int val){
    binary_node* current=node;
    if(node==nullptr){
        node=new binary_node();
        node->content=val;
        return node;
    }
    while(true){
        if(current->content>val){
            if(current->left==nullptr) {
                current->left=new binary_node();
                current->left->content=val;
                break;
            }
            else{
                current=current->left;
            }
        }
        else{
            if(current->right==nullptr){
                current->right=new binary_node();
                current->right->content=val;
                break;
            }
            else{
                current=current->right;
            }
        }
    }
    return node;
}

