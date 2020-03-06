class Solution {
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) 
            return true;
        else if(!p || ! q) 
            return false;

        if(p->val == q->val)
            return isSameTree(p->left,q->right) && isSameTree(p->right, q->left);
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSameTree(root->left,root->right) ;
    }
};