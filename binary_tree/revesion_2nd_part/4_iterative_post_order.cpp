#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

vector<int> postorderTraversal(TreeNode* root) {
    if(root==nullptr) return vector<int>{};
    stack<TreeNode*> st1,st2;
    st2.push(root);
    if(root->left!=nullptr) st1.push(root->left);
    if(root->right!=nullptr) st1.push(root->right);
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
        if(st2.top()->left!=nullptr) st1.push(st2.top()->left);
        if(st2.top()->right!=nullptr) st1.push(st2.top()->right);
    }
    vector<int> ans;
    while(!st2.empty()){
        ans.emplace_back(st2.top()->val);
        st2.pop();
    }   
    return ans;
}