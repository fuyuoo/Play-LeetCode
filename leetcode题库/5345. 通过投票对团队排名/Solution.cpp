// 关键是相同的按字母序比较，参考了别人的在后面加一个标记
// 然后默认的vector<int> 的sort 是依次比较，然后大的就更大
class Solution {
public:
	string rankTeams(vector<string>& votes) {
		int n = votes[0].size();
		string res;
		//二维数组 记录每个人每个奖得多少次
		vector<vector<int>> ranks(26,vector<int>(n+1));
		for (int i = 0; i < votes.size(); ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int n = votes[i][j] - 'A';
				ranks[n][j] ++;
				ranks[n].back() = 26 - n;
			}
			
		}
		sort(ranks.begin(), ranks.end(), greater<vector<int>>());

		for (int i = 0; i < n; ++i)
		{
			res += char(26 - ranks[i].back() + 'A');
		}
		

		return res;
	}
};