// 利用二叉树找到节点，看在哪一边，都小于或者大于就在一边，否则就在两边
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};