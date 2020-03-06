// 因为向左边递归，根节点就是最大值
// 向右边递归，根节点就是最小值
class Solution {
private:
    bool dfs(TreeNode* root,long lower,long upper){
        if(!root)
            return true;
        if(root->val <= lower)
            return false;
        else if(root->val >= upper)
            return false;
        return dfs(root->left,lower,root->val) && dfs(root->right,root->val,upper);

    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MIN,LONG_MAX);
    }
};