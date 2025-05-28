#include<iostream>
#include "1_traversal_recursive.cpp"
using namespace std;

int balancedHeight(binary_node* node){
    if(node==nullptr){
        return 0;
    }
    int lh=balancedHeight(node->left);
    int rh=balancedHeight(node->right);
    if(lh==-1 && rh==-1){
        return -1;
    }
    if(abs(lh-rh)>1){
        return -1;
    }
    return 1+max(lh,rh);
}

bool checkBalanced(binary_node* node){
    if(balancedHeight(node)!=-1) return true;
    else return false;
}

int main(){
    return 0;
}