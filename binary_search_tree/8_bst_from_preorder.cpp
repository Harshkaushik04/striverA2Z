#include<bits/stdc++.h>
#include "binary_node.cpp"
using namespace std;

void build_tree(int preorder_i,int preorder_j,vector<int>& preorder,
    int inorder_i,int inorder_j,unordered_map<int,int>& inorder,TreeNode* godfather,bool direction){
    if((preorder_j<preorder_i)||(inorder_j<inorder_i)) return;
    TreeNode* child;
    if(preorder_j-preorder_i==0 && inorder_j-inorder_i==0){
        if(direction==0) {
            godfather->left=new TreeNode(preorder[preorder_i]);
            child=godfather->left;
        }
        else {
            godfather->right=new TreeNode(preorder[preorder_i]);
            child=godfather->right;
        }
        return;
    }
    int current=preorder[preorder_i];
    int index=inorder[current];
    if(direction==0) {
        godfather->left=new TreeNode(preorder[preorder_i]);
        child=godfather->left;
    }
    else {
        godfather->right=new TreeNode(preorder[preorder_i]);
        child=godfather->right;
    }
    int left_size=index-inorder_i;
    int temp1_i=preorder_i+1;
    int temp1_j=preorder_i+left_size;
    int temp2_i=inorder_i;
    int temp2_j=index-1;
    build_tree(temp1_i,temp1_j,preorder,temp2_i,temp2_j,inorder,child,direction=0);
    temp1_i=preorder_i+left_size+1;
    temp1_j=preorder_j;
    temp2_i=index+1;
    temp2_j=inorder_j;
    build_tree(temp1_i,temp1_j,preorder,temp2_i,temp2_j,inorder,child,direction=1);
}   

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* godfather=new TreeNode(0);
    int preorder_size=preorder.size();
    if(preorder_size==0) return nullptr;
    unordered_map<int,int> inorderMap;
    for(int i=0;i<preorder_size;i++) inorderMap[inorder[i]]=i;
    build_tree(0,preorder_size-1,preorder,0,preorder_size-1,inorderMap,godfather,0); //direction==0 for left, direction==1 for right
    return godfather->left;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    
}