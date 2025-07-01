#include<bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

void itterative_preorder(TreeNode* node){
    stack<TreeNode*> st;
    st.push(node);
    while(!st.empty()){
        TreeNode* current=st.top();
        st.pop();
        cout<<current->content<<endl;
        if(current->right!=nullptr){
            st.push(current->right);
        }        
        if(current->left!=nullptr){
            st.push(current->left);
        }
    }   
}
//wrong
// void itterative_inorder(binary_node* node){
//     stack<binary_node*> st; //stack is made to store those whose left has been released but not yet printed
//     binary_node* current=node;
//     while(current!=nullptr||!st.empty()){
//         if(current->left!=nullptr){
//             st.push(current);
//             current=current->left;
//         }
//         else{
//             cout<<current->content<<endl;
//             if(current->right!=nullptr){
//                 st.push(current->right);
//                 current=current->right;
//             }
//             else{
//                 current=st.top();
//                 st.pop();
//             }
//         }
//     }
// }

int main(){
    return 0;
}