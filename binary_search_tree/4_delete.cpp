#include<bits/stdc++.h>
#include "../binary_tree/1_traversal_recursive.cpp"
using namespace std;

binary_node* customSearch(binary_node* node,int val){
    binary_node* current=node;
    binary_node* prev_current=nullptr;
    if(current==nullptr){
        return nullptr;
    }
    if(current->content==val){
        return node;
    }
    while(current!=nullptr){
        if(current->content==val){
            return prev_current;
        }
        else if(current->content<val){
            prev_current=current;
            current=current->right;
        }
        else{
            prev_current=current;
            current=current->left;
        }
    }
    return nullptr;
}

binary_node* findMaxNode(binary_node* node){
    binary_node* current=node;
    while(current->right!=nullptr) current=current->right;
    return current;
}

binary_node* deleteNode(binary_node* node,int val){
    binary_node* prev_current=customSearch(node,val);
    //either node not found or node==nullptr
    if(prev_current==nullptr) return node;
    //delete root node
    if(prev_current->content==val){
        if(prev_current->left==nullptr && prev_current->right==nullptr) return nullptr;
        else if(prev_current->left!=nullptr && prev_current->right==nullptr){
            return prev_current->left;
        }
        else if(prev_current->right!=nullptr && prev_current->left==nullptr){
            return prev_current->right;
        }
        else{
            binary_node* new_node=prev_current->left;
            binary_node* maxNode=findMaxNode(new_node);
            maxNode->right=prev_current->right;
            delete prev_current;
            return new_node;
        }
    }
    if(prev_current->left->content==val){
        binary_node* deletionNode=prev_current->left;
        if(deletionNode->left==nullptr){
            if(deletionNode->right==nullptr){
                prev_current->left=nullptr;
                delete deletionNode;
            }
            else{
                prev_current->left=deletionNode->right;
                delete deletionNode;
            }
        }
        else{
            prev_current->left=deletionNode->left;
            if(deletionNode->right==nullptr){
                delete deletionNode;
            }
            else{
                binary_node* maxNode=findMaxNode(deletionNode->left);
                maxNode->right=deletionNode->right;
                delete deletionNode;
            }
        }
    }
    else{ //prev_current->right->content==val
        binary_node* deletionNode=prev_current->right;
        if(deletionNode->left==nullptr){
            if(deletionNode->right==nullptr){
                prev_current->right=nullptr;
                delete deletionNode;
            }
            else{
                prev_current->right=deletionNode->right;
                delete deletionNode;
            }
        }
        else{
            prev_current->right=deletionNode->left;
            if(deletionNode->right==nullptr){
                delete deletionNode;
            }
            else{
                binary_node* maxNode=findMaxNode(deletionNode->left);
                maxNode->right=deletionNode->right;
                delete deletionNode;
            }
        }
    }
    return node;
}

int main(){
    return 0;
}