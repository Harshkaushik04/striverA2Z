#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

int DFS(TreeNode* node,int& ans){
    if(node==nullptr) return 0;
    int h1=DFS(node->left,ans);
    int h2=DFS(node->right,ans);
    ans=max(ans,h1+h2);
    return 1+max(h1,h2);
}

int diameterOfBinaryTree(TreeNode* root) {
    int ans=0;
    DFS(root,ans);
    return ans;
}