class Graph {
private:
	int v;
	unordered_map<int, vector<int>> data;
public:
	Graph() {}
	Graph(int v) {
		this->v = v;
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
	Graph g;
    vector<bool> visited;
    void dfs(int v){
        visited[v] = true;
        for(int w : g.AdjList(v)){
            if(!visited[w])
                dfs(w);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        g = Graph(n);
        visited = vector<bool>(n);
        for(int i = 0 ; i < edges.size() ; i++){
            g.AddEdge(edges[i][0],edges[i][1]);
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(i);
                count ++;
            }
        }
        return count;
    }
};