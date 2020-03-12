class Solution {
private:
    int res;
    bool helper(TreeNode* root){
        if(!root)
            return true;
        bool l = helper(root->left);
        bool r = helper(root->right);
        if(root->left && root->left->val != root->val )
            return false;
        if(root->right && root->right->val != root->val)
            return false;
        if(l && r)
            res ++;
        return l && r;
        
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        res = 0;
        helper(root);
        return res;
    }
};