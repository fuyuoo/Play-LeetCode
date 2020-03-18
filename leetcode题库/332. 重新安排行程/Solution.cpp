// 欧拉路径 ，所有的边都要走一遍，不能重复
// 因为要选择字典序，所以使用优先队列
// 但是这种贪心会导致有时候走死路，可以使用图的后序遍历，然后反向输出
class Graph {
private:
	unordered_map<string, priority_queue<string,vector<string>,greater<>>> data;
public:
	Graph() {}

	void AddEdge(string w, string v) {
		data[w].push(v);
	}

	unordered_map<string, priority_queue<string, vector<string>, greater<>>> getdata() {
		return data;
	}
};
class Solution {
private:
	unordered_map<string, priority_queue<string, vector<string>, greater<>>> data;
	deque<string> deq;
	void dfs(string v) {
		while(data[v].size() > 0)
		{
			string w = data[v].top();
			data[v].pop();
			dfs(w);
		}
		deq.emplace_front(v);
		
	}
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		Graph g;
		for (int i = 0; i < tickets.size(); i++)
			g.AddEdge(tickets[i][0], tickets[i][1]);
		data = g.getdata();
		dfs("JFK");
		vector<string> res ;
		while(!deq.empty()){
			res.emplace_back(deq.front());
			deq.pop_front();
		}
		return res;
	}
};