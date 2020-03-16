// 判别是否有环和联通
class Graph {
private:
	int v;
	vector<vector<int>> data;
public:
	Graph() {}
	Graph(int v) {
		this->v = v;
		data = vector<vector<int>>(v, vector<int>());
	}
	void AddEdge(int w, int v) {
		data[w].emplace_back(v);
		data[v].emplace_back(w);

	}
	vector<int> AdjList(int v) {
		return data[v];
	}


};
class Solution {
private:
	vector<bool> visited;
	bool hasCycle;
	Graph g;
	void helper(int v, int parent) {
		visited[v] = true;
		for (int w : g.AdjList(v)) {
			if (!visited[w]) {
				helper(w, v);
			}
			else if (w != parent) {
				hasCycle = true;
				return;
			}
		}
	}
public:
	bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0 && n == 1) return true;
        if(edges.size() == 0) return false; 
		g = Graph(n);
		hasCycle = false;
		visited = vector<bool>(n, false);
		for (int i = 0; i < edges.size(); i++) {
			g.AddEdge(edges[i][0], edges[i][1]);
		}
		helper(edges[0][0],edges[0][0]);
		for (int i = 0; i < visited.size(); ++i)
		{
			if (visited[i] == false)
			{
				return false;
			}
		}
		return !hasCycle ;
	}
};