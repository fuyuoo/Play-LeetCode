class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// 递归结束条件，如果为空返回空；如果找到了，则返回该节点
        if(!root || p == root || q == root)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(!left)
            return right;
        if(!right)
            return left;
        return root;
    }
};