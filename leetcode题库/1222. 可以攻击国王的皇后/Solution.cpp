// 从国王开始向八个方向走，记录碰到的第一个
class Solution {
public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
		vector<vector<bool>> grid(8, vector<bool>(8));
		for (int i = 0; i < queens.size(); i++) {
			grid[queens[i][0]][queens[i][1]] = true;
		}
		vector<vector<int>> res;
		int x = king[0];
		int y = king[1];
		int xoffset[] = {1,1,0,-1,-1, -1, 0, 1};
		int yoffset[] = {0,1,1, 1, 0,-1,-1,-1};
		int nx = x;
		int ny = y;
		for (int i = 0; i < 8; ++i)
		{

			while (nx >=0 && nx < 8 && ny >= 0 && ny < 8)
			{

				if (grid[nx][ny])
				{
					res.emplace_back(vector<int>({ nx,ny }));
					break;
				}
				nx += xoffset[i];
				ny += yoffset[i];
			}
			nx = x;
			ny = y;
			
		}
			
		return res;
	}
};