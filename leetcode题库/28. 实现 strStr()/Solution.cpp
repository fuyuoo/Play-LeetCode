// 得到最长前缀后缀数组，然后通过数组来进行kmp算法
class Solution {
private:
	vector<int> getLPS(string s)
    {

		int n = s.size();
		vector<int> res(n);
		int i = 1, len = 0;
		while (i < n)
		{
			if(s[i] == s[len])
			{
				res[i++] = ++len;
			}else if(len > 0)
			{
				len = res[len - 1];
			}else
			{
				i++;
			}
			
			
		}
		return res;
	}
public:
	int strStr(string haystack, string needle) {
		int n = haystack.size(),m = needle.size();
        if( m == 0)
            return 0;
		vector<int> lps = getLPS(needle);
		int i = 0, j = 0;

		while (i < n)
		{
			if(haystack[i] == needle[j])
			{
				i++;
				j++;
				if (j == m)
					return i - m;
			}else if(j > 0)
			{
				j = lps[j - 1];
			}else
			{
				i++;
			}
			
		}
		return -1;
	}
};