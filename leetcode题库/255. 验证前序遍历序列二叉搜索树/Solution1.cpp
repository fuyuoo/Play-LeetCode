class Solution {
private:
	bool helper(vector<int>& preorder, int l, int r) {
		if (l >= r)
			return true;
		int pivot = preorder[l];
		int i;
		for (i = l + 1; i <= r; i++) {
			if (preorder[i] > pivot)
				break;
		}
		int rl = i;
		for (; i <= r; i++) {
			if (preorder[i] < pivot)
				return false;
		}
		return helper(preorder, l + 1, rl-1) && helper(preorder, rl, r);

	}
public:
	// 因为是二叉搜索树，根节点比左大 比右小
	bool verifyPreorder(vector<int>& preorder) {
		return helper(preorder, 0, preorder.size()-1);
	}
};