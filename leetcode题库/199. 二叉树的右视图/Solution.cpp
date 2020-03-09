class Solution {
private:
    vector<int> res;
    void dfs(TreeNode* root,int n){
        if(!root)
            return ;
        if(res.size() == n)
            res.emplace_back(root->val);
        dfs(root->right,n+1);
        dfs(root->left,n+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        res.clear();
        dfs(root,0);
        return res;
    }
};