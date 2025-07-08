#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

int widthOfBinaryTree(TreeNode* root) {
    queue<pair<TreeNode*,double>> q;
    q.push(make_pair(root,0));
    pair<TreeNode*,double> current;
    double maxi=0,mini=0,ans=1;
    while(!q.empty()){
        int qSize=q.size();
        mini=q.front().second;
        maxi=q.back().second;
        for(int i=0;i<qSize;i++){
            current=q.front();
            q.pop();
            if(current.first->left!=nullptr) q.push(make_pair(current.first->left,2*(current.second-mini)+1));
            if(current.first->right!=nullptr) q.push(make_pair(current.first->right,2*(current.second-mini)+2));
        }
        if(ans<maxi-mini+1) ans=maxi-mini+1;
    }
    return ans;
}