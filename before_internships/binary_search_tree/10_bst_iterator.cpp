#include<bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

class BSTIterator {
    public:
        void inorder(TreeNode* root,vector<int>& arr){
            if(root==nullptr) return;
            inorder(root->left,arr);
            arr.emplace_back(root->val);
            inorder(root->right,arr);
        }
        TreeNode* root;
        int current_index=-1;
        vector<int> arr;
        BSTIterator(TreeNode* root) {
            this->root=root;
            this->current_index=-1;
            this->arr=vector<int>{};
            inorder(this->root,this->arr);
        }
        int next() { //assuming next always exists as given in q
            current_index++;
            return arr[current_index];
        }
        
        bool hasNext() {
            return(current_index+1<static_cast<int>(arr.size()));
        }
    };