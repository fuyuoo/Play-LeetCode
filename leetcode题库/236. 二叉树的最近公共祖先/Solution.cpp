class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        // 找到其中一个节点的父亲，因为值不唯一，所以不会出现重复的
        if(p == root || q == root)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 说明在右边
        if(!left)
            return right;
        if(!right)
            return left;
        // 一边一个
        if(left && right)
            return root;
        // 语法原因，因为肯定存在，所以不会走到
        return nullptr;
    }
};