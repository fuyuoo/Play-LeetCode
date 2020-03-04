class Solution {
private:
	vector<int> getLPS(string& needle){
		int n = needle.size();
		vector<int> LPS(n);
		int i = 1;     // 要从1 开始，因为第一个肯定默认为0，同时不能用自己和自己比       
		int len = 0;
		while(i < n){
			if(needle[i] == needle[len])
				LPS[i++] = ++len;
			else if(len > 0)
				len = LPS[len - 1];
			else{
				i++;
			}
		}
		return LPS;
	}
public:
    int strStr(string haystack, string needle) {
		if(needle.size() == 0) return 0;		// 看题目要求
		vector<int> LPS = getLPS(needle);
		int i = 0;
		int j = 0;
		int n = needle.size();
		while(i < haystack.size()){
			if(haystack[i] == needle[j]){
				i++;
				j++;
				if(j == n)
					return i-n;
			}else if (j > 0){
				j = LPS[j-1];
			}else{
				i++;
			}
		}
		return -1;
    }
};