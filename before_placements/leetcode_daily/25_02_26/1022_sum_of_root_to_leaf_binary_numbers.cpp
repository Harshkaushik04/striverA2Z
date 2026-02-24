#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int calculateValue(vector<int>& arr){
    int length=size(arr);
    int value=0;
    for(int i=0;i<length;i++){
        value+=arr[i]*pow(2,length-i-1);
    }
    return value;
}

void traversal(TreeNode* root,vector<int>& arr,int& ans){
    if(root==nullptr) return;
    if(root->left!=nullptr){
        arr.emplace_back(root->left->val);
        traversal(root->left,arr,ans);
    }
    if(root->right!=nullptr){
        arr.emplace_back(root->right->val);
        traversal(root->right,arr,ans);
    }
    if(root->left==nullptr && root->right==nullptr){
        int value=calculateValue(arr);
        ans+=value;
    }
    arr.pop_back();
}

int sumRootToLeaf(TreeNode* root) {
    if(root==nullptr) return 0;
    if(root->left==nullptr && root->right==nullptr) return root->val;
    int ans=0;
    vector<int> arr;
    arr.emplace_back(root->val);
    traversal(root,arr,ans);
    return ans;        
}

int main(){ 
    return 0;
}