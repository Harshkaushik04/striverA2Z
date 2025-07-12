#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

unordered_map<int,vector<int>> convertToAdjList(TreeNode* root){
    TreeNode* prev_node=nullptr;
    queue<pair<TreeNode*,TreeNode*>> q;
    q.push(make_pair(root,nullptr));
    unordered_map<int,vector<int>> adjList;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            pair<TreeNode*,TreeNode*> current=q.front();
            q.pop();
            adjList[current.first->val]=vector<int>{};
            if(current.second!=nullptr) adjList[current.first->val].emplace_back(current.second->val);
            if(current.first->left!=nullptr){
                q.push(make_pair(current.first->left,current.first));
                adjList[current.first->val].emplace_back(current.first->left->val);
            }
            if(current.first->right!=nullptr){
                q.push(make_pair(current.first->right,current.first));
                adjList[current.first->val].emplace_back(current.first->right->val);
            }
        }
    }
    return adjList;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<int,vector<int>> adjList=convertToAdjList(root);
    unordered_map<int,int> vis;
    for(auto& p:adjList) vis[p.first]=-1;
    queue<int> q;
    q.push(target->val);
    vis[target->val]=1;
    if(k==0) return vector<int>{target->val};
    int distance=0;
    vector<int> ans;
    while(!q.empty()){
        if(distance+1>k) break;
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            int current=q.front();
            q.pop();
            for(int neighbor:adjList[current]){
                if(vis[neighbor]==-1){
                    vis[neighbor]=1;
                    q.push(neighbor);
                    if(distance+1==k) ans.emplace_back(neighbor);
                }
            }
        }
        distance++;
    }
    return ans;
}