// 叶子节点 相当于深度为1，然后统计
class Solution {
private:
    vector<vector<int>> res;
    int helper(TreeNode* root){
        if(!root)
            return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        int depth = max(l,r) + 1;
        if(res.size() < depth)
            res.resize(depth);
        res[depth-1].emplace_back(root->val);
        return max(l,r) + 1;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        res.clear();
        helper(root);
        return res;
    }
};