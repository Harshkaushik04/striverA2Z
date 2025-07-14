#include<bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

void inorder(TreeNode* root,vector<int>& arr){
    if(root==nullptr) return;
    inorder(root->left,arr);
    arr.emplace_back(root->val);
    inorder(root->right,arr);
}

bool findTarget(TreeNode* root, int k) {
    vector<int> arr;
    inorder(root,arr);
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        if(arr[i]+arr[j]==k) return true;
        else if(arr[i]+arr[j]<k) i++;
        else j--;
    }
    return false;
}