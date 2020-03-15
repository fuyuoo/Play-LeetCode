class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int n = s.size();
		vector<int> costs(n);
		for (int i = 0; i <n; i++) 
			costs[i] = abs(s[i] - t[i]);
		int start = 0;
		int curCost = 0;
		int maxLen = 0;
		for (int i = 0; i < n; ++i)
		{
			curCost += costs[i];
			while(curCost > maxCost){
				curCost -= costs[start];
				start++;
			}
			maxLen = max(maxLen, i - start+1 );
		}
		return maxLen;
		
	}
};