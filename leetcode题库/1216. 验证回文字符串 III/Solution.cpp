// 得到最长回文子串，然后通过字符串长度判别
class Solution {
private:
	int getLongestPalindrome(string s)
	{
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n,0));
		for (int i = s.size() - 1; i >=0; --i)
		{
			dp[i][i] = 1;
			for (int j = i+1; j < s.size(); ++j)
			{
				if (s[i] == s[j])
				{
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}else
				{
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[0][n-1];
	}
public:
	bool isValidPalindrome(string s, int k) {
		int len = getLongestPalindrome(s);
		return s.size() - k <= len;
	}
};