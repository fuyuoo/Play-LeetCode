/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 递归 找到左右最大的那个
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int left = maxDepth(root->left) ;
        int right = maxDepth(root->right) ;
        return max(left,right) + 1;
    }
};