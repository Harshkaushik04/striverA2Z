#include<bits/stdc++.h>
#include "../TreeNode.cpp"
using namespace std;

int isSumProperty(Node *root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return 1;
    int left_data = (root->left ? root->left->data : 0);
    int right_data = (root->right ? root->right->data : 0);
    if (root->data != left_data + right_data)
        return 0;
    return isSumProperty(root->left) && isSumProperty(root->right);
}

