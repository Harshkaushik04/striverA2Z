#include<bits/stdc++.h>
#include "1_traversal_recursive.cpp"
using namespace std;

int maxSum(binary_node* node,int* sum){
    if(node==nullptr){
        return 0;
    }
    int lSum=max(0,maxSum(node->left,sum));
    int rSum=max(0,maxSum(node->right,sum));
    *sum=max(*sum,lSum+rSum+node->content);
    return max(lSum,rSum)+node->content;
}

int maxPathSum(binary_node* node){
    int sum=0;
    int* pointer=&sum;
    maxSum(node,pointer);
    return sum;
}

int main(){
    return 0;
}