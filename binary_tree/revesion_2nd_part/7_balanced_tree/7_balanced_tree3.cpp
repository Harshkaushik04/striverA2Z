#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

int DFS(TreeNode* node,bool& ans){
    if(node==nullptr) return 0;
    int h1=DFS(node->left,ans);
    int h2=DFS(node->right,ans);
    if(abs(h1-h2)>1) ans=false;
    return 1+max(h1,h2);
}

bool isBalanced(TreeNode* root) {
    bool ans=true;
    DFS(root,ans);
    return ans;
}