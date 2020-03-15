// 同时递归，找到满足是二叉搜索树的就开始计数
class Solution {
private:
    bool isBST(TreeNode* root){
        return isBST(root,INT_MIN,INT_MAX);
    }
    bool isBST(TreeNode* root,int low,int high){
        if(!root) return true;

        return root->val > low && root->val< high && isBST(root->left,low,root->val) && isBST(root->right,root->val,high);
    }
    int getCount(TreeNode* root){
        if(!root)
            return 0;
        int l = getCount(root->left);
        int r = getCount(root->right);
        return l + r + 1;
    }

public:
    int largestBSTSubtree(TreeNode* root) {
        if(!root) return 0;
        if(isBST(root)) return getCount(root);
        int l = largestBSTSubtree(root->left);
        int r = largestBSTSubtree(root->right);
        return max(l,r);
    }
};