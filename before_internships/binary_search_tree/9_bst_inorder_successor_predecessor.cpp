#include<bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

// pair<Node*,Node*> searchBST(Node* root, int data) {
//     Node* parent=root;
//     if(root->data==data) return pair<Node*,Node*>{root,root};
//     Node* current=root;
//     while(current!=nullptr){
//         if(current->data<data) {
//             parent=current;
//             current=current->right;
//         }
//         else if(current->data>data){
//             parent=current;
//             current=current->left;
//         }
//         else return pair<Node*,Node*>{parent,current};
//     }
//     return {nullptr,nullptr};
// }

// Node* find_left_rightmost(Node* node){
//     Node* current;
//     if(node->left!=nullptr) current=node->left;
//     else return nullptr;
//     while(current->right!=nullptr) current=current->right;
//     return current;
// }

// Node* find_right_leftmost(Node* node){
//     Node* current;
//     if(node->right!=nullptr) current=node->right;
//     else return nullptr;
//     while(current->left!=nullptr) current=current->left;
//     return current;
// }

// vector<Node*> findPreSuc(Node* root, int key) {
//     // code here
//     pair<Node*,Node*> p=searchBST(root,key);
//     Node* parent=p.first;
//     Node* node=p.second;
//     if(parent==node){
//         Node* pred=find_left_rightmost(node);
//         Node* succ=find_right_leftmost(node);
//         return vector<Node*>{pred,succ};
//     }
//     else if(parent->left==node){
//         Node* pred=find_left_rightmost(node);
//         Node* succ=find_right_leftmost(node);
//         if(succ==nullptr) succ=parent;
//         return vector<Node*>{pred,succ};
//     }
//     else{
//         Node* pred=parent;
//         Node* succ=find_right_leftmost(node);
//         return vector<Node*>{pred,succ};
//     }
//     return vector<Node*>{nullptr,nullptr};
// }

void modifiedInorder(Node* root,int key,Node*& ans1,Node*& ans2){
    if(root==nullptr) return;
    modifiedInorder(root->left,key,ans1,ans2);
    if(ans1!=nullptr){
        if(root->data<key && ans1->data<root->data) ans1=root;
    }
    else{
        if(root->data<key) ans1=root;
    }
    if(ans2!=nullptr){
        if(root->data>key && ans2->data>root->data) ans2=root;
    }
    else{
        if(root->data>key) ans2=root;
    }
    modifiedInorder(root->right,key,ans1,ans2);
}

vector<Node*> findPreSuc(Node* root, int key) {
    Node* pred=nullptr;
    Node* succ=nullptr;
    modifiedInorder(root,key,pred,succ);
    return vector<Node*>{pred,succ};
}