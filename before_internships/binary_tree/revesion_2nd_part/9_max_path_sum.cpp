#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

int DFS(TreeNode* node,int& ans){ //outputs maximum 
    if(node==nullptr) return 0;
    if(node->left==nullptr && node->right==nullptr) {
        ans=max(ans,node->val);
        return node->val;
    }
    int ans1=DFS(node->left,ans);
    int ans2=DFS(node->right,ans);
    ans=max(ans,max(0,ans1)+max(0,ans2)+node->val);
    int maxi=max(0,ans1);
    maxi=max(maxi,ans2);
    return maxi+node->val;
}

int maxPathSum(TreeNode* root) {
    int ans=INT32_MIN;
    DFS(root,ans);
    return ans;
}