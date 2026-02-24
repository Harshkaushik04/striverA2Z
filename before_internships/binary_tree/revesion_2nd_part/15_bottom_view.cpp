#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;
  
vector<vector<int>> verticalTraversal(Node* root) {
    vector<vector<int>> actual_ans;
    if(root==nullptr) return actual_ans;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    unordered_map<int,vector<pair<int,int>>> mpp; //{column:{row,data}}
    pair<Node*,int> current;
    int level=0;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            current=q.front();
            q.pop();
            if(mpp.find(current.second)!=mpp.end()) mpp[current.second].emplace_back(make_pair(level,current.first->data));
            else mpp[current.second]=vector<pair<int,int>>{make_pair(level,current.first->data)};
            if(current.first->left!=nullptr) q.push(make_pair(current.first->left,current.second-1));
            if(current.first->right!=nullptr) q.push(make_pair(current.first->right,current.second+1));
        }
        level++;
    }
    vector<vector<pair<int,int>>> ans;
    vector<int> keys;
    for(auto& p:mpp) keys.emplace_back(p.first);
    sort(keys.begin(),keys.end());
    int ssize=keys.size();
    for(int i=0;i<ssize;i++) ans.emplace_back(mpp[keys[i]]);
    for(vector<pair<int,int>>& vec:ans){
        vector<int> temp;
        for(pair<int,int>& p:vec) temp.emplace_back(p.second);
        actual_ans.emplace_back(temp);
    }
    return actual_ans;
}

vector<int> bottomView(Node *root) {
    // code here
    vector<vector<int>> vt=verticalTraversal(root);
    vector<int> ans;
    for(vector<int> vec:vt) if(vec.size()>0) ans.emplace_back(vec[vec.size()-1]);
    return ans;
}