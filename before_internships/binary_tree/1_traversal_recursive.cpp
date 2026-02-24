#include<bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

void preOrderTraversal(TreeNode* pointer){
    if(pointer==nullptr){
        return;
    }
    cout<<pointer->content<<endl;
    preOrderTraversal(pointer->left);
    preOrderTraversal(pointer->right);
}
void inOrderTraversal(TreeNode* pointer){
    if(pointer==nullptr){
        return;
    }
    inOrderTraversal(pointer->left);
    cout<<pointer->content<<endl;
    inOrderTraversal(pointer->right);
}
void postOrderTraversal(TreeNode* pointer){
    if(pointer==nullptr){
        return;
    }
    postOrderTraversal(pointer->left);
    postOrderTraversal(pointer->right);
    cout<<pointer->content<<endl;
}

vector<vector<int>> levelOrderTraversal(TreeNode* root){ //BFS
    TreeNode* current;
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> levels;
    while(!q.empty()){
        int height=q.size();
        vector<int> level;
        for(int i=0;i<height;i++){
            current=q.front();
            q.pop();
            level.emplace_back(current->content);
            if(current->left!=nullptr){
                q.push(current->left);
            }
            if(current->right!=nullptr){
                q.push(current->right);
            }
        }
        levels.emplace_back(level);
    }
    return levels;
}

