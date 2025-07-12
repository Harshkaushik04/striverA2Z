#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

void modifiedInorder(TreeNode* root,int& time,int k,int& ans){
    if(root==nullptr) return;
    if(ans!=-1) return;
    modifiedInorder(root->left,time,k,ans);
    time++;
    if(time==k){
        ans=root->val;
        return;
    }
    modifiedInorder(root->right,time,k,ans);

}

int kthSmallest(TreeNode* root, int k) {
    int time=0,ans=-1;
    modifiedInorder(root,time,k,ans);
    return ans;
}