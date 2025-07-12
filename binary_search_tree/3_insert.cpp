#include<bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

TreeNode* insertNode(TreeNode* node,int val){
    TreeNode* current=node;
    if(node==nullptr){
        node=new TreeNode();
        node->content=val;
        return node;
    }
    while(true){
        if(current->content>val){
            if(current->left==nullptr) {
                current->left=new TreeNode();
                current->left->content=val;
                break;
            }
            else{
                current=current->left;
            }
        }
        else{
            if(current->right==nullptr){
                current->right=new TreeNode();
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

