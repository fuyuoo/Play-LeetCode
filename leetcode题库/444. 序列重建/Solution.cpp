// 拓扑排序 但是数据很烦
// 因为每次都是度为0才加入，如果有多个就可以是很多选项所以是false
class Solution {
public:
	bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
		int n = org.size();

		if (n == 0 || seqs.size() == 0)
			return false;

		// 考虑seqs里头元素为空列表的情况, 已经数字超过n或者<=0的情况
		set<int> numSet;
		for (auto list : seqs) {

			for (int num : list) {
				if (num <= 0 || num > n) 
					return false;
				numSet.insert(num);
			}
		}
		if (numSet.size() < n)
			return false;

		unordered_map<int, vector<int>> g;
		vector<int> indegree(org.size() + 1);
		for (vector<int>& t : seqs) {
            if(t.empty()) continue;
			for (int i = 0; i < t.size() - 1; i++) {
				g[t[i]].emplace_back(t[i + 1]);
				indegree[t[i + 1]]++;
			}
		}
		queue<int> q;

		for (int i = 1; i < indegree.size(); i++)
			if (indegree[i] == 0)
				q.push(i);
		if (q.size() == 0)
			return false;
		while (!q.empty()) {
			if (q.size() > 1)
				return false;;
			int v = q.front();
			q.pop();
			for (int w : g[v]) {
				indegree[w]--;
				if (indegree[w] == 0)
					q.push(w);
			}
		}
		for (int i = 1; i < indegree.size(); i++)
			if (indegree[i] > 0)
				return false;
		return true;

	}
};