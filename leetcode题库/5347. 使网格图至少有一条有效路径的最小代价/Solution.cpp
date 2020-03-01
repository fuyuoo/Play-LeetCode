// 我没有想明白的一点就是，现在的bfs即使是遍历到了结束点，也没有结束，依然继续，也就是全遍历了一遍
// 但是为啥dfs不能起作用
// 思路：使用Bfs按棋盘的方向进行走，如果是正好它的规则则不增加消耗，
// 如果是需要改变方向 && 改变这一步到下一步的cost比它原来更小则更新（dijkstra），并且入队

class Solution
{
private:
	vector<vector<int>> offset = { {0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
public:
	int minCost(vector<vector<int>>& grid)
	{
		int m = grid.size();
		int n = grid[0].size();
		queue<vector<int>> q;
		vector<vector<int>> dis(m, vector<int>(n, -1));
		q.push({ 0, 0, 0 });
		while (!q.empty())
		{
			int x = q.size();
			for (int i = 0; i < x; ++i)
			{
				vector<int> cur = q.front();
				q.pop();
				int x = cur[0];
				int y = cur[1];
				int cost = cur[2];

				if (x == m - 1 && y == n - 1)
					continue;
				int val = grid[x][y];
				for (int j = 1; j < 5; ++j)
				{
					int nx = x + offset[j][0];
					int ny = y + offset[j][1];
					if (nx >= 0 && nx < m && ny >= 0 && ny < n)
					{
						int addCost = j == val ? 0 : 1;
						if (dis[nx][ny] == -1 || dis[nx][ny] > addCost + cost)
						{
							dis[nx][ny] = addCost + cost;
							q.push({ nx,ny,dis[nx][ny] });
						}
					}
				}
			}

			
		}
		return max(0,dis[m-1][n-1]);
	}
};