// 就是中序遍历结果再建树
class Solution {
private:
	vector<int> vec;
	void dfs(TreeNode* root) {
		if (!root)
			return;
		dfs(root->left);
		vec.emplace_back(root->val);
		dfs(root->right);
	}
	TreeNode* helper(int l, int r) {
		if (l > r)
			return nullptr;
		int mid = l + (r - l) / 2;
		TreeNode* node = new TreeNode(vec[mid]);
		node->left = helper(l, mid - 1);
		node->right = helper(mid + 1, r);
		return node;
	}
public:
	TreeNode* balanceBST(TreeNode* root) {
		vec.clear();
		dfs(root);
		return helper(0, vec.size() - 1);

	}
};