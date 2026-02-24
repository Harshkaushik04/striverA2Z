#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

unordered_map<int,vector<int>> convertToAdjList(Node* root){
    Node* prev_node=nullptr;
    queue<pair<Node*,Node*>> q;
    q.push(make_pair(root,nullptr));
    unordered_map<int,vector<int>> adjList;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            pair<Node*,Node*> current=q.front();
            q.pop();
            adjList[current.first->data]=vector<int>{};
            if(current.second!=nullptr) adjList[current.first->data].emplace_back(current.second->data);
            if(current.first->left!=nullptr){
                q.push(make_pair(current.first->left,current.first));
                adjList[current.first->data].emplace_back(current.first->left->data);
            }
            if(current.first->right!=nullptr){
                q.push(make_pair(current.first->right,current.first));
                adjList[current.first->data].emplace_back(current.first->right->data);
            }
        }
    }
    return adjList;
}

int minTime(Node* root, int target){
    unordered_map<int,vector<int>> adjList=convertToAdjList(root);
    unordered_map<int,int> vis;
    for(auto& p:adjList) vis[p.first]=-1;
    queue<int> q;
    q.push(target);
    vis[target]=1;
    int distance=0;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            int current=q.front();
            q.pop();
            for(int neighbor:adjList[current]){
                if(vis[neighbor]==-1){
                    vis[neighbor]=1;
                    q.push(neighbor);
                }
            }
        }
        distance++;
    }
    return distance;
}