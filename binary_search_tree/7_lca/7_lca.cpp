#include<bits/stdc++.h>
#include "../binary_tree.cpp"
using namespace std;

queue<TreeNode*> search(TreeNode* root,TreeNode* to_search){
    queue<TreeNode*> q;
    TreeNode* current=root;
    while(current!=nullptr){
        q.push(current);
        if(current->val>to_search->val) current=current->left;
        else if(current->val<to_search->val) current=current->right;
        else return q;
    }
    return q;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    queue<TreeNode*> p_path=search(root,p);
    if(root==q) return root;
    TreeNode* prev_node=nullptr;
    TreeNode* current=root;
    while(!p_path.empty()){
        TreeNode* top_node=p_path.front();
        p_path.pop();
        if(current->val==top_node->val) prev_node=current;
        else return prev_node;
        prev_node=current;
        if(current->val>q->val) current=current->left;
        else if(current->val<q->val) current=current->right;
        else return q;
    }
    return p;
}