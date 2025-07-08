#include<bits/stdc++.h>
#include "../TreeNode.cpp"
using namespace std;

int maxDepth(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int ans=0;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            TreeNode* current=q.front();
            q.pop();
            if(current->left!=nullptr) q.push(current->left);
            if(current->right!=nullptr) q.push(current->right);
        }
        ans++;
    }
    return ans;
}