// 简单的BFS
class Solution
{
private:
	vector<vector<int>> offset = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
	vector<vector<int>> dis;

	bool check(int x, int y, vector<vector<int>>& g)
	{
		return x >= 0 && x < g.size() && y >= 0 && y < g[x].size() && g[x][y] == 0 && dis[x][y] == -1;
	}

public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid)
	{
		int w = grid[0].size();
		int h = grid.size();
		if (w == 1 && h == 1)
			return 1;
		if (grid[0][0])
		{
			return -1;
		}
		dis = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1));
		dis[0][0] = 1;
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		while (!q.empty())
		{
			pair<int, int> cur = q.front();
			q.pop();
			for (int i = 0; i < offset.size(); ++i)
			{
				int newX = cur.first + offset[i][0];
				int newY = cur.second + offset[i][1];
				if (check(newX, newY, grid))
				{
					dis[newX][newY] = dis[cur.first][cur.second] + 1;

                    if(newX == h - 1 && newY == w -1){
                        return dis[h - 1][w - 1] ;
                    }

					q.push(make_pair(newX, newY));
				}
			}
		}
		return dis[h - 1][w - 1] ;
	}
};