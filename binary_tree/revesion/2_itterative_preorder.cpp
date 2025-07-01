#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

vector<int> preorderTraversal(TreeNode* root) {
    if(root==nullptr) return vector<int>{};
    stack<TreeNode*> st;
    st.push(root);
    vector<int> ans;
    while(!st.empty()){
        if(st.top()!=nullptr){
            TreeNode* current=st.top();
            st.pop();
            ans.emplace_back(current->val);
            st.push(current->right);
            st.push(current->left);
        }
        else st.pop();
    }
    return ans;
}