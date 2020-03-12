class Solution {
private:
	priority_queue < pair<double, int>, vector<pair<double, int>>, greater<> > pq;
	void binarySearch(TreeNode* root, double target) {
		if (!root)
			return;
		pq.push({ abs(root->val - target), root->val });

        binarySearch(root->left, target);
        binarySearch(root->right, target);
	}
public:
	vector<int> closestKValues(TreeNode* root, double target, int k) {
		vector<int> res;
		if (!root) return res;
		binarySearch(root, target);
		while (k--) {
			res.emplace_back(pq.top().second);
			pq.pop();
		}
		return res;
	}
};