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