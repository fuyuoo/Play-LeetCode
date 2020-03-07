/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 把右边的插到左边的最右边
class Solution {
public:
    void flatten(TreeNode* root) {

        while(root){
            
            if(root->left){
                TreeNode* preRight = root->right;
                TreeNode* preleft = root->left;
                TreeNode* tmp = root->left;
                while(tmp->right)
                    tmp = tmp->right;
                tmp->right = preRight;
                root->right = preleft;
                root->left = nullptr;
            }
            root = root->right;

        }

    }
};