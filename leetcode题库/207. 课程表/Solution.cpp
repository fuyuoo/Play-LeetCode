class Graph {
private:
	int v;
	vector<vector<int>> data;

public:
	Graph(){}
	Graph(int v) {
		this->v = v;
		data = vector<vector<int>>(v, vector<int>());
	}
	void AddEdge(int w, int v) {
		data[w].emplace_back(v);
	}
	vector<int> AdjList(int v) {
		return data[v];
	}

};
class Solution {
private:
	vector<bool> visited;  // 表示已经访问过了
	vector<bool> tag;   // 表示这个路径正在访问中，如果还接触则表示成环
	bool hasCycle = false;;
	Graph g;
	void dfs(int v) {
		tag[v] = true;
		visited[v] = true;
		for (int w : g.AdjList(v)) {
			if (!visited[w]) {
				dfs(w);
			}
			else if (tag[w]) {
				hasCycle = true;
				return;
			}
		}
		tag[v] = false;

	}
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		g = Graph(numCourses);
		visited = vector<bool>(numCourses, false);
		tag = vector<bool>(numCourses, false);
		for (int i = 0; i < prerequisites.size(); i++) {
			g.AddEdge(prerequisites[i][1], prerequisites[i][0]);
		}
		for (int i = 0; i < numCourses; i++) {
			if (!visited[i] && !hasCycle) {
				dfs(i);
			}
		}

		return !hasCycle;

	}
};