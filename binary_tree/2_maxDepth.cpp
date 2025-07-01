#include<bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;
//mycode
// int Depth(binary_node* left,binary_node* right){
//     if(left==nullptr && right==nullptr){
//         return 1;
//     }
//     else if(left==nullptr && right!=nullptr){
//         return 1+Depth(right->left,right->right);
//     }
//     else if(left!=nullptr && right==nullptr){
//         return 1+Depth(left->left,left->right);
//     }
//     else{
//         return 1+max(Depth(right->left,right->right),Depth(left->left,left->right));
//     }
// }

int Depth(TreeNode* node) {
    if (node == nullptr) return 0;
    return 1 + max(Depth(node->left), Depth(node->right));
}

int main(){
    return 0;
}