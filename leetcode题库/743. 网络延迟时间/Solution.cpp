// disjksrtra 
// 因为没有负权边，所以最大点就是最终时间
class Solution
{
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K)
	{
		vector<vector<int>> g(N + 1, vector<int>(N + 1, -1));
		for (int i = 0; i < times.size(); i++)
			g[times[i][0]][times[i][1]] = times[i][2];

		queue<int> q;
		q.push(K);
		vector<int> dis(N + 1, INT_MAX);
		dis[K] = 0;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int i = 1; i < g[v].size(); i++) {
				if (g[v][i] != -1 && dis[v] + g[v][i] < dis[i]) {
					dis[i] = dis[v] + g[v][i];
					q.push(i);
				}
			}
		}
		int res = 0;
		for (int i = 1; i <= N; ++i) {
			res = max(dis[i], res);
		}
		return res == INT_MAX ? -1 : res;;
	}
};