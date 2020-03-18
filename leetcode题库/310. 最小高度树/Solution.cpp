// 解法很神奇，因为要找到最小高度的，肯定是在重心，可能是一个或者两个
// 然后要找到这个重心，其实各个叶子节点都是一样的，因为都要遍历到，所以可以层序遍历叶子节点
// 直到只有一个或者两个，这就是重心
// 所以使用拓扑排序，无向图，度为1 的入队
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		unordered_map<int, vector<int>> g;
		vector<int> degree(n);
		for (int i = 0; i < edges.size(); i++) {
			int x = edges[i][0];
			int y = edges[i][1];
			g[x].emplace_back(y);
			g[y].emplace_back(x);
			degree[x]++;
			degree[y]++;
		}
		queue<int> q;
		for (int i = 0; i < degree.size(); i++) {
			if (degree[i] == 1)
				q.push(i);
		}
		int res = n;
		if (res == 1)
			return { 0 };
		while (res != 1 && res != 2) {
			int len = q.size();
			res -= len;
			for (int i = 0; i < len; i++) {
				int v = q.front();
				q.pop();
				for (int w : g[v]) {
					degree[w]--;
					if (degree[w] == 1)
						q.push(w);
				}
			}
		}
		vector<int> resvec;
		while (!q.empty()) {
			resvec.emplace_back(q.front());
			q.pop();
		}

		return resvec;
	}
};