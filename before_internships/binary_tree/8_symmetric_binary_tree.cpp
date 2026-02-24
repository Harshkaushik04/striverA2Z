#include<bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

void mirroPreOrder(TreeNode* node,vector<int>* cl2){
    if(node==nullptr) return;
    cl2->emplace_back(node->content);
    mirroPreOrder(node->right,cl2);
    mirroPreOrder(node->left,cl2);
}

void preOrder(TreeNode* node,vector<int>* cl1){
    if(node==nullptr) return;
    cl1->emplace_back(node->content);
    preOrder(node->left,cl1);
    preOrder(node->right,cl1);
}

bool checkSymmetry(TreeNode* node){
    vector<int> cl1,cl2;
    vector<int>* cl1Pointer=&cl1;
    vector<int>* cl2Pointer=&cl2;
    if(node->left==nullptr && node->right==nullptr) return true;
    else if(node->left!=nullptr && node->right==nullptr) return false;
    else if(node->left==nullptr && node->right!=nullptr) return false;
    preOrder(node->left,cl1Pointer);
    mirroPreOrder(node->right,cl2Pointer);
    if(cl1==cl2) return true;
}

int main(){
    return 0;
}