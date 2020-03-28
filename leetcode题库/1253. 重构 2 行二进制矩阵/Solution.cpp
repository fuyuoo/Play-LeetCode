// 直接模拟
class Solution {
public:
	vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
		int n = colsum.size();
		vector<vector<int>> g(2, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			if (colsum[i] == 2) {
				if (upper <= 0 || lower <= 0)
					return {};
				g[0][i] = 1;
				g[1][i] = 1;
				upper--;
				lower--;
			}
		}
		int i = 0;
		while ( i < n && upper) {
			if (colsum[i] == 1)
			{
				g[0][i] = 1;
				upper--;
			}
			i++;
		}
		if (upper > 0)
			return {};

		i = n - 1;
		while (i >=0 && lower) {
			if (colsum[i] == 1)
			{
				g[1][i] = 1;
				lower--;
			}
			i--;
		}
		if (lower > 0)
			return {};
		for(int t = 0 ; t < n ; t++)
		{
			if (g[0][t] + g[1][t] != colsum[t])
				return {};
		}
		return g;

	}
};