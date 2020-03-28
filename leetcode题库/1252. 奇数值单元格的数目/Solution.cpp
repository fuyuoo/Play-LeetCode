// 直接模拟，统计
class Solution {
public:
	int oddCells(int n, int m, vector<vector<int>>& indices) {
		vector<vector<int>> g(n,vector<int>(m,0));
		for (vector<int>& v : indices) {
			int x = v[0];
			int y = v[1];
			for (int i = 0; i < m; i++) {
				g[x][i]++;
			}
			for (int i = 0; i < n; i++) {
				g[i][y]++;
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res += (g[i][j] & 1);
			}
		}
		return res;
	}
};