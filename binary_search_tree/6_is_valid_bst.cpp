#include<bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

void inorder(TreeNode* root,long& maxi,bool& ans){
    if(root==nullptr) return;
    if(!ans) return; 
    inorder(root->left,maxi,ans);
    if(!ans) return;
    if(maxi>=root->val){
        ans=false;
        return;
    }
    else maxi=root->val;
    inorder(root->right,maxi,ans);

}

bool isValidBST(TreeNode* root) {
    long maxi=2*(long)INT32_MIN;
    bool ans=true;
    inorder(root,maxi,ans);
    return ans;
}