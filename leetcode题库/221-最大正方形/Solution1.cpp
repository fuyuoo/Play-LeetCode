#include <algorithm>
#include <vector>
using namespace std;

// 使用一个临时变量储存左上的临时变量，使用一维数组
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
					// 因为当前有一个1，所以取左边上面和左上三个的最小值+1，最小值的意思就是能否构成正方形
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
