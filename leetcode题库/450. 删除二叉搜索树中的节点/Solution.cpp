/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* minNode(TreeNode* node){
        if(!node->left)
            return node;
        return minNode(node->left);
    }
    TreeNode* deleteMinNode(TreeNode* node){
        if(!node->left)
            return node->right;
        node->left = deleteMinNode(node->left);
        return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }else if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }else{
            if(!root->left)
                return root->right;
            else if(!root->right)
                return root->left;
            else{
                TreeNode* sucessor = minNode(root->right);
                sucessor->right  = deleteMinNode(root->right);
                sucessor->left = root->left;
                return sucessor;
            }
        }

    }
};