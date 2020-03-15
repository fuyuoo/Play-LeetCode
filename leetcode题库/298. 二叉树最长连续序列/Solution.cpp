// 连续意味着+1
class Solution {
private:
	int res;
	void helper(TreeNode* root, int preVal, int count) {
		if (!root) return;
		if (root->val == preVal + 1) {
			res = max(res, count+1);
			helper(root->left, root->val, count + 1);
			helper(root->right, root->val, count + 1);
		}
		else {
			helper(root->left, root->val, 1);
			helper(root->right, root->val, 1);
		}
	}
public:
	int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
		res = 1;
		helper(root->left, root->val, 1);
		helper(root->right, root->val, 1);

		return res;
	}
};