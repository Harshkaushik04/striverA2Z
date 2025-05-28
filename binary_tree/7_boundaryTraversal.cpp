#include<bits/stdc++.h>
#include "1_traversal_recursive.cpp"
using namespace std;

bool isLeaf(binary_node* current){
    if(current->left==nullptr && current->right==nullptr){
        return true;
    }
    return false;
}

vector<int> leftBoundary(binary_node* node){
    binary_node* current=node;
    vector<int> l;
    while(!isLeaf(current)){
        if(current->left!=nullptr){
            l.emplace_back(current->content);
            current=current->left;
        }
        else{
            if(current->right!=nullptr){
                l.emplace_back(current->content);
                current=current->right;
            }
        }
    }
    return l;
}

void leafs(binary_node* node,vector<int>* collectingList){
    //preorder
    if(node==nullptr){
        return;
    }
    leafs(node->left,collectingList);
    if(isLeaf(node)){
        collectingList->emplace_back(node->content);
    }
    leafs(node->right,collectingList);
}

vector<int> rightBoundary(binary_node* node){
    binary_node* current=node;
    stack<int> st;
    vector<int> result;
    if(node->right==nullptr){
        return result;
    }
    current=current->right;
    st.push(current->content);
    while(!isLeaf(current)){
        if(current->right!=nullptr){
            st.push(current->content);
            current=current->right;
        }
        else{
            if(current->left!=nullptr){
                st.push(current->content);
                current=current->left;
            }
        }
    }
    int len=st.size();
    for(int i=0;i<len;i++){
        result.emplace_back(st.top());
        st.pop();
    }
    return result;
}

void boundaryTraversal(binary_node* node){
    vector<int> left=leftBoundary(node);
    vector<int> leafsList;
    vector<int>* pointer=&leafsList;
    leafs(node,pointer);
    vector<int> right=rightBoundary(node);
    int leftSize=left.size();
    int leafSize=leafsList.size();
    int rightSize=right.size();
    for(int i=0;i<leftSize;i++){
        cout<<left[i]<<endl;
    }
    for(int i=0;i<leafSize;i++){
        cout<<leafsList[i]<<endl;
    }
    for(int i=0;i<rightSize;i++){
        cout<<right[i]<<endl;
    }
}

int main(){
    return 0;
}