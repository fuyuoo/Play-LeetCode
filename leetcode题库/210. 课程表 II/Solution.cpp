// 拓扑排序
class Graph {
private:
	int v;
	vector<vector<int>> data;
	vector<int> indegree;
public:
	Graph(){}
	Graph(int v) {
		this->v = v;
		data = vector<vector<int>>(v, vector<int>());
		indegree = vector<int>(v,0);
	}
	void AddEdge(int w, int v) {
		data[w].emplace_back(v);
		indegree[v]++;
	}
	vector<int> AdjList(int v) {
		return data[v];
	}
	vector<int> getIndegree(){
		return indegree;
	}

};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    	vector<int> res;
        Graph g(numCourses);
		vector<bool> visited = vector<bool>(numCourses, false);
        for (int i = 0; i < prerequisites.size(); i++) {
			g.AddEdge(prerequisites[i][1], prerequisites[i][0]);
		}
		vector<int> indegree = g.getIndegree();
		queue<int> q;
		for(int i = 0 ; i < numCourses ; i++)
			if(indegree[i] == 0)
				q.push(i);

		while(!q.empty()){
			int v = q.front();
			res.emplace_back(v);
			q.pop();
			for(int w : g.AdjList(v)){
				if(!visited[w]){
					indegree[w]--;
					if(indegree[w] == 0)
						q.push(w);
				}

			}
		}
		for(int i = 0 ; i < numCourses ; i++)
			if(indegree[i] != 0)
				return {};
		return res;
    }
};