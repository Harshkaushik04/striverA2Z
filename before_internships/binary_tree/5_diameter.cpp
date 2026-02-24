#include<bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

int height(TreeNode* node,int* maxi){
    if(node==nullptr){
        return 0;
    }
    int lh=height(node->left,maxi);
    int rh=height(node->right,maxi);
    *maxi=max(*maxi,lh+rh);
    return 1+max(lh,rh);
}

int diameter(TreeNode* node){
    int maxi=0;
    int* pointer=&maxi;
    height(node,pointer);
    return maxi;
}

int main(){
    return 0;
}