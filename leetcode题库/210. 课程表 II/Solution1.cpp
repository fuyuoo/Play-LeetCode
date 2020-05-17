class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, vector<int>> map;
		vector<int> indegree(numCourses);
		vector<bool> visited(numCourses);
		vector<int> res;
		for (int i = 0; i < prerequisites.size(); i++) {
			map[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
			indegree[prerequisites[i][0]]++;
		}
		queue<int> q;
		for (int i = 0; i < indegree.size(); i++) {
			if (indegree[i] == 0) {
				q.push(i);
				visited[i] = true;
				res.emplace_back(i);
			}
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int v : map[node]) {
				if (!visited[v]) {
					indegree[v]--;
					if (indegree[v] == 0) {
						q.push(v);
						visited[v] = true;
						res.emplace_back(v);
					}
				}
			}
		}
		for (int i = 0; i < visited.size(); i++)
			if (!visited[i])
				return vector<int>();
		return res;
	}
};