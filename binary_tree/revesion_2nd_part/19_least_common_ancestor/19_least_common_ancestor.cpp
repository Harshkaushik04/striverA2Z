#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

void printArr(vector<TreeNode*> arr){
    for(TreeNode* node:arr) cout<<node->val<<" ";
    cout<<endl;
}
void path_to_node(TreeNode* node_to_reach,TreeNode* temp,vector<TreeNode*>& ans,bool reached){
    ans.emplace_back(temp);
    if(temp==node_to_reach) {
        reached=true;
        return;
    }
    if(reached) return;
    if(temp->left!=nullptr) path_to_node(node_to_reach,temp->left,ans,reached);
    if(reached) return;
    if(temp->right!=nullptr) path_to_node(node_to_reach,temp->right,ans,reached);
    if(reached) return;
    ans.pop_back();
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> ans1,ans2;
    bool reached=false;
    TreeNode* temp=root;
    path_to_node(p,temp,ans1,reached);
    path_to_node(q,temp,ans2,reached);
    int ssize=min(ans1.size(),ans2.size());
    for(int i=1;i<ssize;i++) if(ans1[i]!=ans2[i]) return ans1[i-1];
    return ans1[ssize-1];
}
int main(){
    TreeNode* root=new TreeNode(3);
    TreeNode* temp=root;
    temp->left=new TreeNode(5);
    temp->right=new TreeNode(1);
    temp=root->left;
    temp->left=new TreeNode(6);
    temp->right=new TreeNode(2);
    temp=root->right;
    temp->left=new TreeNode(0);
    temp->right=new TreeNode(8);
    temp=root->left->right;
    temp->left=new TreeNode(7);
    temp->right=new TreeNode(4);
    TreeNode* p=root->left;
    TreeNode* q=root->left->right->right;
    TreeNode* ans=lowestCommonAncestor(root,p,q);
    cout<<"ans:"<<ans->val<<endl;
    return 0;
}