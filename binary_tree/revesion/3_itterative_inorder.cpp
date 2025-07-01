#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;
//not done

//     vector<int> inorderTraversal(TreeNode* root) {
//     if(root==nullptr) return vector<int>{};
//     stack<TreeNode*> st;
//     TreeNode* current;
//     current=root->left;
//     st.push(current);
//     vector<int> ans;
//     while(!st.empty()){
//         while(current!=nullptr){
//             st.push(current);
//             current=current->left;
//         }
//         while(current==nullptr){
//             if(st.empty()) break;
//             ans.emplace_back(st.top()->val);
//             current=st.top()->right;
//             st.pop();
//         }
//     } 
//     return ans;
// }