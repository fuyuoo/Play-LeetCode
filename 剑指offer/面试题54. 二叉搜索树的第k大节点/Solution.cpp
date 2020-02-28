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
    vector<int> memo;
    void dfs(TreeNode* node){
        if(!node)
            return ;
        dfs(node->left);
        memo.emplace_back(node->val);
        dfs(node->right);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        dfs(root);
        return memo[memo.size() - k];
    }
};