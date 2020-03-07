/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> res;
    void helper(TreeNode* root, int sum,vector<int> cur){
        if(!root)
            return ;
        cur.emplace_back(root->val);
        if(root->val == sum){
            if(!root->left && !root->right){
                res.emplace_back(cur);
            }
        }
        helper(root->left, sum - root->val, cur);
        helper(root->right, sum - root->val, cur);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        res.clear();
        helper(root, sum, {});
        return res;
    }
};