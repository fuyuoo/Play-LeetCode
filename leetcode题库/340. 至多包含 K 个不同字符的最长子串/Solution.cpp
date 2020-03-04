// 使用哈希表来记录有多少个不同的字符，然后和其他题目一样（例如最长不重复子串）
class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		int l = 0, r = 0;
		int len = 0;
		unordered_map<char, int> imap;
		while (r < s.size()) {
			imap[s[r]]++;
			while (imap.size() > k ) {
				imap[s[l]]--;
				if (imap[s[l]] == 0)
					imap.erase(s[l]);
				l++;
					
				
			}
			len = max(len, r - l + 1);
			r++;
		}
		return len;
	}
};