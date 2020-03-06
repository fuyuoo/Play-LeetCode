class Solution
{
private:
	TreeNode* helper(vector<int>& inorder, int l, int r, vector<int>& postorder, int m, int n)
	{
		if (l > r || m > n) return nullptr;
		int pivot = l;
		int count = 0;
		while (inorder[pivot] != postorder[n])
		{
			pivot++;
			count++;
		}
		TreeNode* node = new TreeNode(postorder[n]);
		node->left = helper(inorder, l, l + count-1, postorder, m, m + count-1);
		node->right = helper(inorder, l+count+1, r, postorder, m + count, n - 1);
		return node;
	}

public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
};