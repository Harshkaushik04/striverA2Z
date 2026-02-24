#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==nullptr){
        if(q==nullptr) return true;
        else return false;
    }
    else if(q==nullptr){
        if(p==nullptr) return true;
        else return false;
    }
    return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}