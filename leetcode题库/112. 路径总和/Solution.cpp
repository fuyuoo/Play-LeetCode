/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 注意是根节点和叶子节点
class Solution {
private:
    bool haspath;
    void helper(TreeNode* root,int sum){
        if(!root)
            return ;
        if(sum == root->val){
            if(!root->left && !root->right){
                haspath = true;
                return ;
            }
        }
        if(!haspath){
            helper(root->left,sum - root->val);
            helper(root->right,sum - root->val);
        }


    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        haspath = false;
        helper(root,sum);
        return haspath;
    }
};