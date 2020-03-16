/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // 同时dfs 一边寻找前一个点，一边找另外一个点
 // 根据搜索二叉树全遍历
class Solution
{
private:
	bool find(TreeNode* root, int target)
	{
		if (!root) return false;
		if (target == root->val)
			return true;
		else if (target > root->val)
		{
			if (find(root->right, target))
				return true;
		}
		else
		{
			if (find(root->left, target))
				return true;
		}
        return false;

	}

public:
	bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target)
	{
        if (!root1)                                                
			return false;

		int another = target - root1->val;
		if (another == root2->val)
			return true;
		else if (another > root2->val)
	 	{
			if (find(root2->right,another))
				return true;
		}else
		{
			if (find(root2->left, another))
				return true;
		}
		return twoSumBSTs(root1->left, root2, target) || twoSumBSTs(root1->right, root2, target);
	}
};