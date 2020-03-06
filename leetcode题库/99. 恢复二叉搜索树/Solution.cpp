// 并不是最优解，可以使用O(1)空间复杂度解决
// 这个是利用引用解决的
class Solution {
	vector<TreeNode*> res;
	void dfs(TreeNode* root) {
		if (!root)
			return;

		dfs(root->left);
		if (root)
			res.push_back(root);
		dfs(root->right);
	}
public:
	void recoverTree(TreeNode* root) {
		res.clear();
		dfs(root);
		int a = -1, b = -1;
		for (int i = 0; i < res.size() ; i++) {
			if ((  i + 1 < res.size() && res[i]->val >= res[i + 1 ]->val) ||
				(i - 1 >= 0 &&  res[i]->val <= res[i - 1]->val)) {
				if (a == -1)
					a = i;
				else
					b = i;
			}
		}
		int tmp = res[a]->val;
		res[a]->val = res[b]->val;
		res[b]->val = tmp;

	}
};