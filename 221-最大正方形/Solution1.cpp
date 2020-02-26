#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int n = matrix.size();
		if (n == 0)
			return 0;
		int m = matrix[0].size();
		vector<int> dp(m + 1, 0);
		int maxlen = 0, prev = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int tmp = dp[j];
				if (matrix[i - 1][j - 1] == '1') {
					dp[j] = min(min(dp[j], dp[j - 1]), prev) + 1;
					maxlen = max(maxlen, dp[j]);
				}
				else {
					dp[j] = 0;
				}
				prev = tmp;
			}
		}
		return maxlen * maxlen;
	}
};
int main()
{
	vector<vector<char>> input = { {'1'} };
	Solution s;
	s.maximalSquare(input);
}
