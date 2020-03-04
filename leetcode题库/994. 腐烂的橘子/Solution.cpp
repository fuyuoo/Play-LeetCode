// 先遍历一遍，然后多源bfs
class Solution {
private:
	vector<int> xoffset = { 1,0,-1,0 };
	vector<int> yoffset = { 0,-1,0,1 };
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int n = grid.size();
		if (n == 0) return 0;
		int m = grid[0].size();
		int sumTime = 0;
		queue<vector<int>> q;
		int finecount = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 2) {
					q.push({ i,j });
				}
				else if (grid[i][j] == 1)
					finecount++;
			}
		}
        if(finecount == 0) return 0;
		int count = 0;
		while (!q.empty()) {
			int t = q.size();
			for (int i = 0; i < t; i++) {
				vector<int> cur = q.front();
				q.pop();
				for(int j = 0 ; j < 4 ; j++)
				{
					int nx = cur[0] + xoffset[j];
					int ny = cur[1] + yoffset[j];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
						q.push({ nx,ny });
						finecount--;
						grid[nx][ny] = 2;
					}
				}

			}
			count++;
		}
		return finecount == 0 ? count-1 : -1;
	}
};