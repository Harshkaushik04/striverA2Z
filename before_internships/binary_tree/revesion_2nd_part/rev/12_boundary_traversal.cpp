#include<bits/stdc++.h>
#include "../TreeNode.cpp"
using namespace std;

void modifiedInorder(Node* root,vector<int>& ans,Node* actual_root){
    if(root==nullptr) return;
    modifiedInorder(root->left,ans,actual_root);
    if(root->left==nullptr && root->right==nullptr && root!=actual_root) ans.emplace_back(root->data);
    modifiedInorder(root->right,ans,actual_root);
}

vector <int> boundaryTraversal(Node* root){
    if(root==nullptr) return vector<int>{};
    vector<int> ans;
    Node* temp=root->left;
    ans.emplace_back(root->data);
    while(temp!=nullptr && (temp->left!=nullptr||temp->right!=nullptr)){
        if(temp!=root) ans.emplace_back(temp->data);
        if(temp->left!=nullptr) temp=temp->left;
        else temp=temp->right;
    }
    modifiedInorder(root,ans,root);
    stack<int> st;
    temp=root->right;
    while(temp!=nullptr && (temp->left!=nullptr||temp->right!=nullptr)){
        if(temp!=root) st.push(temp->data);
        if(temp->right!=nullptr) temp=temp->right;
        else temp=temp->left;
    }
    while(!st.empty()){
        ans.emplace_back(st.top());
        st.pop();
    }
    return ans;
}
