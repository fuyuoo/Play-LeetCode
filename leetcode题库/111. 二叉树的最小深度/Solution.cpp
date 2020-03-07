/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 注意空节点返回0 叶子节点返回1
 // 左右有孩子返回最小，只有一个返回一个
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if(!root->left || ! root->right)
            return l + r + 1;
        return min(l,r) + 1;
    }
};