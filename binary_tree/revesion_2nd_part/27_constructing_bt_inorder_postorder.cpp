#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

void build_tree(int inorder_i,int inorder_j,unordered_map<int,int>& inorder_map,
                int postorder_i,int postorder_j,vector<int>& postorder,TreeNode* godfather,bool direction){
    if(inorder_i-inorder_j==0 && postorder_i-postorder_j==0){
        if(direction==0) godfather->left=new TreeNode(postorder[postorder_j]);
        else godfather->right=new TreeNode(postorder[postorder_j]);
        return;
    }
    if(inorder_i-inorder_j>0 || postorder_i-postorder_j>0) return;
    TreeNode* child;
    int index=inorder_map[postorder[postorder_j]];
    if(direction==0) {
        godfather->left=new TreeNode(postorder[postorder_j]);
        child=godfather->left;
    }
    else {
        godfather->right=new TreeNode(postorder[postorder_j]);
        child=godfather->right;
    }
    int temp1_i,temp1_j,temp2_i,temp2_j,left_size;
    temp1_i=inorder_i;
    temp1_j=index-1;
    left_size=index-inorder_i;
    temp2_i=postorder_i;
    temp2_j=postorder_i+left_size-1;
    build_tree(temp1_i,temp1_j,inorder_map,temp2_i,temp2_j,postorder,child,0);
    temp1_i=index+1;
    temp1_j=inorder_j;
    temp2_i=postorder_i+left_size;
    temp2_j=postorder_j-1;
    build_tree(temp1_i,temp1_j,inorder_map,temp2_i,temp2_j,postorder,child,1);
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    TreeNode* godfather=new TreeNode(0);
    int inorder_size=inorder.size();
    unordered_map<int,int> inorder_map;
    for(int i=0;i<inorder_size;i++) inorder_map[inorder[i]]=i;
    build_tree(0,inorder_size-1,inorder_map,0,inorder_size-1,postorder,godfather,0);
    return godfather->left;
}