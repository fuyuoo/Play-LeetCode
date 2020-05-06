
class Solution
{
public:
	int mincostTickets(vector<int>& days, vector<int>& costs)
	{
		int n = days[days.size() - 1];
		vector<int> dp(n + 1, 0);
		for (int i = 0; i < days.size(); i++)
			dp[days[i]] = INT_MAX;   // 标记当前是旅游日
		for (int i = 1; i < dp.size(); i++)
		{
			if (dp[i] == 0)          // 如果当前不是旅游日
				dp[i] = dp[i - 1];
			else
			{
				dp[i] = min({
					dp[i],
					dp[i - 1] + costs[0],
					dp[max(0, i - 7)] + costs[1],
					dp[max(0, i - 30)] + costs[2]

				});
			}
		}
		return dp[dp.size() - 1];
	}
};