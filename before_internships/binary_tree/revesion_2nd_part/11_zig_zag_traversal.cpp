#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root==nullptr) return vector<vector<int>>{};
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> ans;
    int j=0;
    while(!q.empty()){
        int ssize=q.size();
        vector<int> miniAns;
        for(int i=0;i<ssize;i++){
            TreeNode* current=q.front();
            q.pop();
            miniAns.emplace_back(current->val);
            if(current->left!=nullptr) q.push(current->left);
            if(current->right!=nullptr) q.push(current->right);
        }
        if(j%2==1) reverse(miniAns.begin(),miniAns.end());
        ans.emplace_back(miniAns);
        j++;
    }
    return ans;
}
