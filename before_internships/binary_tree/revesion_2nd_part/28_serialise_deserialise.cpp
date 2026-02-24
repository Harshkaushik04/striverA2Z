#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    string ans;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            TreeNode* current=q.front();
            q.pop();
            if(current!=nullptr){
                if(i!=qSize-1) ans.append(to_string(current->val)+',');
                else ans.append(to_string(current->val)+'|');
            }
            else{
                if(i!=qSize-1) ans.append("N,");
                else ans.append("N|");
                continue;
            }
            q.push(current->left);
            q.push(current->right);
        }
    }
    return ans;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    TreeNode* godfather=new TreeNode(0);
    // godfather->left=new TreeNode(0);
    queue<TreeNode*> q;
    q.push(godfather);
    TreeNode* current_node=q.front();
    q.pop();
    string current;
    int leftDone=1; // 0 for neither left,right  1 for left and not right 2 for both left and right
    for(char ch:data){
        if(ch!=',' && ch!='|') current.push_back(ch);
        else if(ch=='|'||ch==','){
            if(leftDone==2){ //current_node needs to be changed
                current_node=q.front();
                q.pop();
                if(current=="N")current_node->left=nullptr;
                else{
                    current_node->left=new TreeNode(stoi(current));
                    q.push(current_node->left);
                }
                leftDone=1;
            }
            else if(leftDone==1){
                if(current=="N") current_node->right=nullptr;
                else{
                    current_node->right=new TreeNode(stoi(current));
                    q.push(current_node->right);
                }
                leftDone=2;
            }
            else{
                if(current=="N") current_node->left=nullptr;
                else{
                    current_node->left=new TreeNode(stoi(current));
                    q.push(current_node->left);
                }
                leftDone=1;
            }
            current.clear();
        }
    }
    return godfather->right;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    string ans=serialize(root);
    cout<<"ans:"<<ans<<endl;
    TreeNode* ans_node=deserialize(ans);
    return 0;
}