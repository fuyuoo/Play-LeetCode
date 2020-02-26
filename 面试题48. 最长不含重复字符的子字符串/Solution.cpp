// 双指针 使用哈希表来记录重复元素
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int l = 0, r = 0;
		unordered_map<char, int> imap;

		int maxLen = 0;
		while (r < s.size())
		{
			imap[s[r]]++;
			while (imap[s[r]] > 1)
			{
				imap[s[l]]--;
				l++;
			}
			maxLen = max(r - l + 1, maxLen);
			r++;
		}
		return maxLen;
	}
};