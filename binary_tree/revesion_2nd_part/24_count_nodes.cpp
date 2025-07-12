#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

int find_height(TreeNode* root){
    TreeNode* current=root;
    int distance=0;
    while(current!=nullptr){
        current=current->left;
        distance++;
    }
    return distance;
}

bool whether_exists_mid(int mid,TreeNode* root){
    stack<bool> st;
    while(mid!=1){
        if(mid%2==0){
            mid/=2;
            st.push(true);
        }
        else{
            mid=(mid-1)/2;
            st.push(false);
        }
    }
    TreeNode* current=root;
    while(!st.empty()){
        if(st.top()) current=current->left;
        else current=current->right;
        st.pop();
    }
    if(current==nullptr) return false;
    return true;
}

int countNodes(TreeNode* root) {
    if(root==nullptr) return 0;
    if(root->left==nullptr && root->right==nullptr) return 1;
    int h=find_height(root);
    int left=1;
    int right=pow(2,h)-1;
    int mid=(left+right)/2;
    bool ans;
    while(left<right){
        mid=(left+right)/2;
        ans=whether_exists_mid(mid,root);
        if(ans) left=mid+1;
        else right=mid-1;
    }
    if(whether_exists_mid(left,root)) return left;
    return mid;
}