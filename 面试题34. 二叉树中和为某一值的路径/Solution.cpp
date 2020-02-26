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
	vector<vector<int>> ret;
	void helper(TreeNode* root, vector<int>& cur, int sum) {
		cur.emplace_back(root->val);
        if(!root->left && !root->right){
		    if (sum == root->val) 
                ret.emplace_back(cur);
		}
        if(root->left)
		    helper(root->left, cur, sum - root->val);
        if(root->right)
		    helper(root->right, cur, sum - root->val);
        cur.pop_back();


	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
            return ret;
		vector<int> cur;
		helper(root, cur, sum);
		return ret;
	}
};