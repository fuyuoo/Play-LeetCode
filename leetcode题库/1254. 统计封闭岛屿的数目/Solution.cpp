// dfs 如果接近了边则没有封闭
class Solution {
private:
	int xoffset[4] = { 0,1,0,-1 };
	int yoffset[4] = { 1,0,-1,0 };
	bool flag;
	void dfs(vector<vector<int>>& grid, int x, int y) {
		grid[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + xoffset[i];
			int ny = y + yoffset[i];
			if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
			{
				flag = false;
				continue;
			}
			if (grid[nx][ny] == 0)
				dfs(grid, nx, ny);
		}
	}
public:
	int closedIsland(vector<vector<int>>& grid) {
		int res = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 0) {
					flag = true;
					dfs(grid, i, j);
					if (flag == true)
						res++;
				}
			}
		}
		return res;
	}
};