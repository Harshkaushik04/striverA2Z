#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

void Inorder(Node* root,vector<int>& leafs,Node* actual_root){
    if(root==nullptr) return;
    Inorder(root->left,leafs,actual_root);
    if(root->left==nullptr && root->right==nullptr && root!=actual_root) leafs.emplace_back(root->data);
    Inorder(root->right,leafs,actual_root);
}

vector <int> boundaryTraversal(Node* root){
    //your code goes here
    if(root==nullptr) return vector<int>{};
    vector<int> ans;
    ans.emplace_back(root->data);
    stack<int> rightBoundary;
    Node* current=root->left;
    while(current!=nullptr && !(current->left==nullptr && current->right==nullptr)){
        ans.emplace_back(current->data);
        if(current->left!=nullptr) current=current->left;
        else if(current->right!=nullptr) current=current->right;
    }
    Inorder(root,ans,root);
    current=root->right;
    while(current!=nullptr && !(current->left==nullptr && current->right==nullptr)){
        rightBoundary.push(current->data);
        if(current->right!=nullptr) current=current->right;
        else if(current->left!=nullptr) current=current->left;
    }
    while(!rightBoundary.empty()){
        ans.emplace_back(rightBoundary.top());
        rightBoundary.pop();
    }
    return ans;
}