// 统计各个经理手下的人id
// 然后形成一个树，遍历树，相当于层序遍历，找到最长路径
class Solution
{
public:
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
	{
		vector<vector<int>> headcount(n, vector<int>());
		for (int i = 0; i < manager.size(); i++)
		{
			if (manager[i] != -1)
				headcount[manager[i]].emplace_back(i);
		}

		queue<pair<int, int>> q; // id and cost
		q.push({ headID, informTime[headID] });
		int res =0 ;
		while (!q.empty())
		{
			vector<int> nextIDs = headcount[q.front().first];
			int cost = q.front().second;
			res = max(res, cost);
			q.pop();
			for (int i = 0; i < nextIDs.size(); ++i)
			{
				q.push({ nextIDs[i], informTime[nextIDs[i]] + cost });
			}
		}
		return res;
	}
};