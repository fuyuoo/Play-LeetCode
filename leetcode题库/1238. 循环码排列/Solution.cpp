// 格雷福编码，反转
class Solution {
public:
	vector<int> circularPermutation(int n, int start) {
		vector<int> res;
		for (int i = 0; i < 1 << n; i++)
			res.emplace_back(i ^ i / 2);
		auto s = find(res.begin(), res.end(), start);
		reverse(res.begin(),s );
		reverse(s, res.end());
		reverse(res.begin(), res.end());
		return res;

	}
};