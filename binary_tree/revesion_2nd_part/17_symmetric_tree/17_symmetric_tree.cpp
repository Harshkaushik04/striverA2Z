#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

void printArr(vector<int>& arr){
    int arrSize=arr.size();
    for(int i=0;i<arrSize;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

bool isSymmetric(TreeNode* root) {
    if(root==nullptr) return true;
    queue<TreeNode*> q;
    TreeNode* current;
    q.push(root);
    while(!q.empty()){
        int qSize=q.size();
        vector<int> temp,temp1;
        for(int i=0;i<qSize;i++){
            current=q.front();
            q.pop();
            if(current==nullptr) temp.emplace_back(200);
            else{
                temp.emplace_back(current->val);
                q.push(current->left);
                q.push(current->right);
            }
        }
        temp1=temp;
        reverse(temp1.begin(),temp1.end());
        if(temp==temp1) continue;
        else return false;
    }
    return true;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);
    bool ans=isSymmetric(root);
    cout<<ans<<endl;
    return 0;
}