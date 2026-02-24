#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

vector<int> rightSideView(TreeNode* root) {
    if(root==nullptr) return vector<int>{};
    queue<TreeNode*> q;
    q.push(root);
    unordered_map<int,vector<int>> mpp; //{column:{row,data}}
    TreeNode* current;
    int level=0;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            current=q.front();
            q.pop();
            if(mpp.find(level)!=mpp.end()) mpp[level].emplace_back(current->val);
            else mpp[level]=vector<int>{current->val};
            if(current->right!=nullptr) q.push(current->right);
            if(current->left!=nullptr) q.push(current->left);
        }
        level++;
    }
    vector<int> ans;
    vector<int> keys;
    for(auto& p:mpp) keys.emplace_back(p.first);
    sort(keys.begin(),keys.end());
    int ssize=keys.size();
    for(int i=0;i<ssize;i++) ans.emplace_back(mpp[keys[i]][0]);
    return ans;
}