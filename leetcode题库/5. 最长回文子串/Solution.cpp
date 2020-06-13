// 使用# 扩充，这样肯定是奇数大小的字符串，使得算法统一
// 然后使用中心扩散，遍历每一个点，然后向外扩散，看当前最多能达到多少回文
class Solution {
private: 
	int getLR(string& s,int l,int r,int n)
	{
		while (l>=0 && r <n &&  s[l] == s[r])
		{
			l--;
			r++;
		}
		return (r - l - 1) ;
	}

public:
	string longestPalindrome(string s) {
		if (s.length() == 0 )
			return "";
		string c = "#";
		for (int i = 0; i < s.size(); ++i)
		{
			c += s[i];
			c += "#";
		}
		int n = c.size();
		int maxLen = -1;
		int maxM = -1;

		for (int i = 1; i < n; ++i)
		{
			if (c[i - 1] == c[i+1])
			{
				int temp = getLR(c, i - 1, i + 1, n);
 				if (temp > maxLen)
				{
					maxLen = temp;
					maxM = i;
				}
			}
			
		}
		// 因为maxm记录的是中心点，所以需要计算
		c = c.substr(maxM - maxLen / 2, maxLen);
		string res = "";
		for (int i = 1; i < c.size(); )
		{
			res += c[i];
			i += 2;
		}

		return res;

		
	}
};