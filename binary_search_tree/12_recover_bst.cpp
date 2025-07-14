#include<bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

void inorder1(TreeNode* root,vector<int>& arr){
    if(root==nullptr) return;
    inorder1(root->left,arr);
    arr.emplace_back(root->val);
    inorder1(root->right,arr);
}

void inorder2(TreeNode* root,vector<int>& arr,int& i){
    if(root==nullptr) return;
    inorder2(root->left,arr,i);
    root->val=arr[i];
    i++;
    inorder2(root->right,arr,i);
}

void recoverTree(TreeNode* root) {
    vector<int> arr;
    inorder1(root,arr);
    sort(arr.begin(),arr.end());
    int i=0;
    inorder2(root,arr,i);
}