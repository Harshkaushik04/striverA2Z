#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

void modifiedPreorder(TreeNode* root,queue<TreeNode*>& q){
    if(root==nullptr) return;
    q.push(root);
    modifiedPreorder(root->left,q);
    modifiedPreorder(root->right,q);
}

void flatten(TreeNode* root) {
    queue<TreeNode*> q;
    modifiedPreorder(root,q);
    TreeNode* godfather=new TreeNode(0);
    TreeNode* current=godfather;
    while(!q.empty()){
        current->left=nullptr;
        current->right=q.front();
        q.pop();
        current=current->right;
    }
}