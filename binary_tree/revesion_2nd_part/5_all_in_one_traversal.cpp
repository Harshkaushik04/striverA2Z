#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

vector<vector<int> > treeTraversal(TreeNode* root){
    //your code goes here
    if(root==nullptr) return vector<vector<int>>{{},{},{}};
    stack<pair<TreeNode*,int>> st;
    st.push(make_pair(root,1));
    vector<vector<int>> ans={{},{},{}};
    while(!st.empty()){
        pair<TreeNode*,int> current=st.top();
        if(current.second==1){
            ans[0].emplace_back(current.first->val);
            st.top().second++;
            if(current.first->left!=nullptr) st.push(make_pair(current.first->left,1));
        }
        else if(current.second==2){
            ans[1].emplace_back(current.first->val);
            st.top().second++;
            if(current.first->right!=nullptr) st.push(make_pair(current.first->right,1));
        }
        else if(current.second==3){
            ans[2].emplace_back(current.first->val);
            st.pop();
        }
    }
    return ans;
}