// 使用一个左边最大数组和一个右边最小数组
// 遍历，直到找到一个位置满足左边最大值小于右边最小值
class Solution {
public:
	int partitionDisjoint(vector<int>& A) {
		int n = A.size();
		vector<int> maxl(n);
		vector<int> minr(n);
		maxl[0] = A[0];
		for (int i = 1; i < n; i++) {
			maxl[i] = max(maxl[i - 1], A[i]);
		}
		minr[n - 1] = A[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			minr[i] = min(minr[i + 1], A[i]);
		}
		for (int i = 1; i < n; i++) {
			if (maxl[i-1] <= minr[i])
				return i;
		}
		return -1;

	}
};