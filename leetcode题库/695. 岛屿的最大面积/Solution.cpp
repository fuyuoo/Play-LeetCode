// 求最大联通分量
class Solution {
private:
	int xoffset[4] = {1,0,-1,0};
	int yoffset[4] = {0,1,0,-1};
	int helper(vector<vector<int>>& grid,int x,int y,int count){
		grid[x][y] = 0;
		int res = 1;
		for(int i = 0 ; i < 4 ; i ++){
			int nx = x + xoffset[i];
			int ny = y + yoffset[i];
			if(nx >= 0 && nx < grid.size()  && ny >=0 && ny < grid[0].size() && grid[nx][ny] == 1){
				res += helper(grid,nx,ny,count+1);
			}

		}
		return res;
	}

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int maxCount = 0;

		for(int i = 0 ; i < m;i++){
			for(int j = 0 ; j < n ;j++){
				if(grid[i][j] == 1){
					maxCount = max(maxCount,helper(grid,i,j,1));
				}
			}
		}
		return maxCount ;
    }
};