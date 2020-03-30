// 字频统计
class Solution {
public:
	int findLucky(vector<int>& arr) {
		unordered_map<int, int> map;
		for (int& t : arr) {
			map[t]++;
		}
		int res = INT_MIN;
		for (auto t : map) {
			if (t.first == t.second)
			{
				res = max(res, t.first);
			}
		}
		return res == INT_MIN? -1 : res;
	}
};