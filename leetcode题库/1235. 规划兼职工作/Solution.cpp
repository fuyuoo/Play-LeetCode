// 先按照结束时间 从小到大排序，这样不会错过一些时间
// 排序之后开始dp  dp[i] 表示该时间获得的最大收益
// 状态转移方程， max(dp[curend],dp[start] + curProfit)
// 因为给的是时间段，所以中间的时间也要补齐
struct WorkTime
{
	int startTime;
	int endTime;
	int profit;

	WorkTime(int s, int e, int p) : startTime(s), endTime(e), profit(p)
	{
	};

	bool operator <(WorkTime j1)
	{
		return endTime < j1.endTime;
	}
};
class Solution
{
public:


	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
	{
		vector<WorkTime> jobs;
		int JobSize = startTime.size();
		for (int i = 0; i < JobSize; i++)
			jobs.emplace_back(WorkTime(startTime[i], endTime[i], profit[i]));

		sort(jobs.begin(), jobs.end(), less<>());
		int maxEndTime = jobs[JobSize - 1].endTime;
		vector<int> dp(maxEndTime + 1, 0);
		int maxProfit = 0;
		int d = 0;
		for (int i = 0; i < JobSize; i++)
		{
			auto job = jobs[i];
			int endTime = job.endTime;
			// 上一个的结束时间和现在的结束时间一致，所以该点的最大收益可能是加上新的
			if (d == endTime)
				dp[endTime] = max(dp[endTime], job.profit + dp[job.startTime]);
			else
			{
				while (d < endTime)
				{
					dp[d + 1] = dp[d];
					d++;
				}
				// 当前最大收益取前面一个或者是该时间段的利润
				dp[endTime] = max(dp[endTime - 1], job.profit + dp[job.startTime]);
			}
			maxProfit = max(maxProfit, dp[endTime]);
		}
		return maxProfit;
	}
};