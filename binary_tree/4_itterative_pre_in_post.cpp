#include<bits/stdc++.h>
#include "1_traversal_recursive.cpp"
using namespace std;

void itterative_preorder(binary_node* node){
    stack<binary_node*> st;
    st.push(node);
    while(!st.empty()){
        binary_node* current=st.top();
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