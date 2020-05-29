// 今天直接秒写出来了，虽然出了些边界问题，但是状态转移方程是正确的
class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;
		vector<int>dp(nums);

		for (int i = 1; i < n; i++) {
			dp[i] = max(dp[i - 1], dp[i] + (i - 2 < 0 ? 0 : dp[i-2]));
		}
		return dp[n - 1];
	}
};