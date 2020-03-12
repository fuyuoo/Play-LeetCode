/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
// 递归写法， 我感觉需要很多的画图
class Solution {
private:
    void helper(Node* root){
        //叶子节点或者空节点返回
        if(!root || (!root->left && !root->right))
            return;
        // 有左右子树则连接
        if(root->left && root->right)
            root->left->next = root->right;
        // 当前连接到兄弟节点的起始点
        Node* cur = root->right? root->right : root->left;
        // 兄弟节点
        Node* tmp = root->next;
        // 找到一个兄弟节点有孩子节点
        while(tmp){
            if(tmp->left){
                cur->next = tmp->left;
                break;
            }else if(tmp->right){
                cur->next = tmp->right;
                break;
            }
            tmp = tmp->next;
        }
        helper(root->right);
        helper(root->left);
    }
public:
    Node* connect(Node* root) {
        helper(root);
        return root;
    }
};