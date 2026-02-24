#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

void go_on_path(Node* node,vector<vector<int>>& ans,vector<int>& temp){
    temp.emplace_back(node->data);
    if(node->left==nullptr && node->right==nullptr) ans.emplace_back(temp);
    if(node->left!=nullptr) go_on_path(node->left,ans,temp);
    if(node->right!=nullptr) go_on_path(node->right,ans,temp);
    temp.pop_back();
}

vector<vector<int>> Paths(Node* root) {
    // code here
    vector<vector<int>> ans;
    if(root==nullptr) return ans;
    vector<int> temp;
    go_on_path(root,ans,temp);
    return ans;
}