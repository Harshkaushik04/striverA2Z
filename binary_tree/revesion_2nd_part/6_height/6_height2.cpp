#include<bits/stdc++.h>
#include "../TreeNode.cpp"
using namespace std;

//dp version is actaully redundant
// int f(TreeNode* root,unordered_map<TreeNode*,int> mpp){
//     if(root==nullptr) return 0;
//     if(mpp.find(root)!=mpp.end()) return mpp[root];
//     mpp[root]=1+max(maxDepth(root->left),maxDepth(root->right));
//     return mpp[root];
// }

// int maxDepth(TreeNode* root) {
//     unordered_map<TreeNode*,int> mpp;
//     return f(root,mpp);
// }

int maxDepth(TreeNode* root) {
    if(root==nullptr) return 0;
    return 1+max(maxDepth(root->left),maxDepth(root->right));
}