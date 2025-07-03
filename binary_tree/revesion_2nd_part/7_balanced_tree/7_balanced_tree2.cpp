#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

int height(TreeNode* node,unordered_map<TreeNode*,int>& mpp){
    if(node==nullptr) return 0;
    if(mpp.find(node)!=mpp.end()) return mpp[node];
    mpp[node]=1+max(height(node->left,mpp),height(node->right,mpp));
    return mpp[node];
}

bool isBalanced(TreeNode* root) {
    if(root==nullptr) return true;
    unordered_map<TreeNode*,int> mpp;
    bool cond=(abs(height(root->left,mpp)-height(root->right,mpp))<=1);
    return isBalanced(root->left) && isBalanced(root->right) && (abs(mpp[root->left]-mpp[root->right])<=1);
}
