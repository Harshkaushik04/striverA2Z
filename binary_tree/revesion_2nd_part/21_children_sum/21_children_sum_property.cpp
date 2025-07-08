#include<bits/stdc++.h>
#include "../TreeNode.cpp"
using namespace std;

int isSumProperty(Node *root) {
    // Add your code here
    queue<Node*> q;
    q.push(root);
    Node* current;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            current=q.front();
            q.pop();
            if(current->left==nullptr && current->right==nullptr) continue;
            else{
                if(current->left==nullptr){
                    if(current->right->data==current->data) q.push(current->right);
                    else return 0;
                }
                else if(current->right==nullptr){
                    if(current->left->data==current->data) q.push(current->left);
                    else return 0;
                }
                else{
                    if(current->data==current->left->data+current->right->data){
                        q.push(current->left);
                        q.push(current->right);
                    }
                    else return 0;
                }
            }
        }
    }
    return 1;
}