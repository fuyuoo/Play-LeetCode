/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 使用后续遍历，后续遍历就是先遍历完子节点，再访问根节点
 // 所以先遍历到底，根据递归结束条件返回结果，如果是找到了（不管是左还是右）,则返回该根节点
 // 如果没有找到，所以根据肯定有祖先节点的情况下，会在另一侧，然后在另一侧继续找
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || p == root || q == root) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(!left)
            return right;
        if(!right)
            return left;
        return root;
    }
};