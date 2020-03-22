// kmp算法的next数组，最长前后缀数组
// 然后得到字符串最后一个字符能匹配多少个字符，就从头开始sub
class Solution {
private:
	vector<int> getnext(string& s)
	{
		int len = 0;
		int i = 1;
		vector<int> lps(s.size());
		while (i < s.size())
			if (s[len] == s[i])
				lps[i++] = ++len;
			else if (len > 0)
				len = lps[len - 1];
			else
				i++;
		return lps;
	}
public:
	string longestPrefix(string s) {
		vector<int> next = getnext(s);
		int n = next[s.size()-1];
		return s.substr(0, n);
	}
};