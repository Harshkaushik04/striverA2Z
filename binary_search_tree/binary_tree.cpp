class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val){
            this->left=nullptr;
            this->right=nullptr;
            this->val=val;
        }
        TreeNode(){
            this->left=nullptr;
            this->right=nullptr;
            this->val=0;
        }
};

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->left=nullptr;
        this->right=nullptr;
        this->data=data;
    }
    Node(){
        this->left=nullptr;
        this->right=nullptr;
        this->data=0;
    }
};