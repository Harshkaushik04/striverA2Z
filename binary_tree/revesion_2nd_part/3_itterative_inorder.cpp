#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

vector<int> inorderTraversal(TreeNode* root) {
    if(root==nullptr) return vector<int>{};
    stack<TreeNode*> st;
    TreeNode* current;
    current=root->left;
    st.push(root);
    vector<int> ans;
    while(true){
        while(current!=nullptr){
            st.push(current);
            current=current->left;
        }
        if(st.empty()) break;
        while(current==nullptr){
            if(st.empty()) break;
            ans.emplace_back(st.top()->val);
            current=st.top()->right;
            st.pop();
        }
    } 
    return ans;
}