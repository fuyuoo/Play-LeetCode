
class Solution {
private:
    int res = INT_MAX;
    TreeNode* pre = nullptr;
    void dfs(TreeNode* node){
        if(node->left)
            dfs(node->left);

        if(pre)
            res = min(res,node->val - pre->val);
        pre = node;

        if(node->right)
            dfs(node->right);
        

    }
public:
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return res;
    }
};