// 可以说是我自己解决的第一个用到贪心的算法把
class Solution {
public:
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
		vector<vector<int>> cache;
		unordered_map<int, int> labelcount;
		for (int i = 0; i < values.size(); i++) {
			cache.emplace_back(vector<int>({ values[i],labels[i] }));
		}
		sort(cache.begin(), cache.end(), [](vector<int>& a, vector<int>& b) {return a[0] > b[0]; });
		int res = 0;
		int count = 0;
		for (int i = 0; i < cache.size() && count < num_wanted; i++) {
			if (labelcount[cache[i][1]] < use_limit) {
				res += cache[i][0];
				labelcount[cache[i][1]]++;
				count++;
			}
		}

		return res;

	}
};