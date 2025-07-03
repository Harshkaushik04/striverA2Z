#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

int f(TreeNode* root,unordered_map<TreeNode*,int>& mpp){
    if(root==nullptr) return 0;
    if(mpp.find(root)!=mpp.end()) return mpp[root];
    mpp[root]=1+max(f(root->left,mpp),f(root->right,mpp));
    return mpp[root];
}

bool modifiedLevelOrder(TreeNode* root,bool ans,unordered_map<TreeNode*,int>& mpp) {
    if(root==nullptr) true;
    queue<TreeNode*> q;
    q.push(root);
    if(!ans) return false;
    while(!q.empty()){
        int ssize=q.size();
        vector<int> miniAns;
        for(int i=0;i<ssize;i++){
            TreeNode* current=q.front();
            if(abs(f(current->left,mpp)-f(current->right,mpp))>1) ans=false;
            if(!ans) break;
            q.pop();
            miniAns.emplace_back(current->val);
            if(current->left!=nullptr) q.push(current->left);
            if(current->right!=nullptr) q.push(current->right);
        }
        if(!ans) break;
    }
    return ans;
}

bool isBalanced(TreeNode* root) {
    if(root==nullptr) return true;
    unordered_map<TreeNode*,int> mpp;
    bool ans=false;
    return modifiedLevelOrder(root,ans,mpp);
}
