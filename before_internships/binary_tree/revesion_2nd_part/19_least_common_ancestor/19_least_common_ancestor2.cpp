#include<bits/stdc++.h>
#include "../TreeNode.cpp"
using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==nullptr) return nullptr;
    if(root==p) return p;
    if(root==q) return q;
    TreeNode* l=lowestCommonAncestor(root->left,p,q);
    TreeNode* r=lowestCommonAncestor(root->right,p,q);
    if(l==nullptr && r==nullptr) return nullptr;
    else if(l!=nullptr && r==nullptr) return l;
    else if(l==nullptr && r!=nullptr) return r;
    else return root;
}