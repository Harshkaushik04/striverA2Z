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

string elementsToString(vector<int>& arr){
    int length=size(arr);
    string ans;
    for(int i=0;i<length;i++){
        ans+=to_string(arr[i]);
        if(i!=length-1){
            ans+="->";
        }
    }
    return ans;
}

void traversal(TreeNode* root,vector<int>& arr,vector<string>& ans){
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
        ans.emplace_back(elementsToString(arr));
    }
    arr.pop_back();
}

vector<string> binaryTreePaths(TreeNode* root) {
    if(root==nullptr) return vector<string>();
    if(root->left==nullptr && root->right==nullptr) return {to_string(root->val)};
    vector<string> ans;
    vector<int> arr;
    arr.emplace_back(root->val);
    traversal(root,arr,ans);
    return ans;
}

int main(){
    
    return 0;
}