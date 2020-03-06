class Solution {
private:
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int l = dfs(root->left);
        if(l == -1) return -1;
        int r = dfs(root->right);
        if(r == -1) return -1;

        if(abs(l - r) >= 2)
            return -1;
        return max(l,r) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        
        return dfs(root) != -1;;
    }
};