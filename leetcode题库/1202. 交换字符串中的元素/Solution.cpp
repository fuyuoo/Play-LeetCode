// 使用并查集，我一开始想到了，但是不会用，还是练的少了
// 我没想到的就是，其实不需要各个分好类，因为可以再在find里面看是否一致
class Solution {
private:
	vector<int> pre;
	int find(int x) {
		if (pre[x] != x) pre[x] = find(pre[x]);
		return pre[x];
	}
	void merge(int p, int q) {
		int rootp = find(p);
		int rootq = find(q);
		if (rootp == rootq) return;
		pre[rootp] = rootq;
	}
public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		pre = vector<int>(s.size());
		for (int i = 0; i < pre.size(); i++)
			pre[i] = i;
		for (int i = 0; i < pairs.size(); i++) {
			merge(pairs[i][0], pairs[i][1]);
		}
		unordered_map<int, vector<char>> map;
		for (int i = 0; i < s.size(); i++) {
			map[find(i)].emplace_back(s[i]);
		}
		for (auto it = map.begin(); it != map.end(); it++) {
			sort(it->second.begin(), it->second.end(), greater<char>());
		}
		for (int i = 0; i < s.size(); ++i)
		{
			int tmp = find(i);
			s[i] = map[tmp].back();
			map[tmp].pop_back();
		}
		return s;
	}
};