class Solution {
public:
    int countNodes(TreeNode* root) {
        int l = 0, r = 0;
        TreeNode* lroot = root;
        TreeNode* rroot = root;

        while(lroot){
            lroot = lroot->left;
            l++;
        }
        while(rroot){  // 是否满二叉树
            rroot = rroot->right;
            r++;
        }
        if( l == r)
            return pow(2,l)-1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};