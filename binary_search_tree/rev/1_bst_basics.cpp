#include<bits/stdc++.h>
#include "../binary_tree.cpp"
using namespace std;

TreeNode* searchBST(TreeNode* root, int val) {
    if(root->val==val) return root;
    TreeNode* current=root;
    while(current!=nullptr){
        if(current->val<val) current=current->right;
        else if(current->val>val) current=current->left;
        else return current;
    }
    return nullptr;
}

int findCeil(Node* root, int input) {
    // Your code here
    if(root->data==input) return input;
    Node* current=root;
    int ans=INT32_MIN;
    while(current!=nullptr){
        if(current->data<input) current=current->right;
        else if(current->data==input) return input;
        else{
            ans=current->data;
            current=current->left;
        }
    }
    if(ans<input) return -1;
    return ans;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root==nullptr){
        root=new TreeNode(val);
        return root;
    }
    TreeNode* current=root;
    while(true){
        if(current->val<val){
            if(current->right==nullptr){
                current->right=new TreeNode(val);
                return root;
            }
            else current=current->right;
        }
        else{//current->val==val not possible given in question
            if(current->left==nullptr){
                current->left=new TreeNode(val);
                return root;
            }
            else current=current->left;
        }
    }
    return root;
}

TreeNode* find_parent(TreeNode* root,int key){
    if(root->val==key) return root;
    TreeNode* current=root;
    TreeNode* parent=root;
    while(current!=nullptr){
        if(current->val>key){
            parent=current;
            current=current->left;
        }
        else if(current->val<key) {
            parent=current;
            current=current->right;
        }
        else return parent;
    }
    return nullptr;
} 

TreeNode* find_min(TreeNode* root){
    TreeNode* current=root;
    if(current==nullptr) return nullptr;
    while(current->left!=nullptr) current=current->left;
    return current;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==nullptr) return nullptr;
    TreeNode* parent=find_parent(root,key);
    if(parent==nullptr) return root;
    else if(parent->val==key){ //key=>root
        if(parent->left==nullptr && parent->right==nullptr) return nullptr;
        else if(parent->left==nullptr) return parent->right;
        else if(parent->right==nullptr) return parent->left;
        else{
            TreeNode* mini=find_min(parent->right);
            mini->left=parent->left;
            return parent->right;
        }
    }
    else if(parent->left!=nullptr && parent->left->val==key){ //parent->left==node to be removed
        TreeNode* current=parent->left;
        if(current->left==nullptr && current->right==nullptr){
            parent->left=nullptr;
            return root;
        }
        else if(current->right==nullptr){
            parent->left=current->left;
            return root;
        }
        else if(current->left==nullptr){
            parent->left=current->right;
            return root;
        }
        else{
            TreeNode* mini=find_min(current->right);
            mini->left=current->left;
            parent->left=current->right;
            return root;
        }
    }
    else{ //parent->right==node to be removed
        TreeNode* current=parent->right;
        if(current->left==nullptr && current->right==nullptr){
            parent->right=nullptr;
            return root;
        }
        else if(current->right==nullptr){
            parent->right=current->left;
            return root;
        }
        else if(current->left==nullptr){
            parent->right=current->right;
            return root;
        }
        else{
            TreeNode* mini=find_min(current->right);
            mini->left=current->left;
            parent->right=current->right;
            return root;
        }
    }
    return root;
}