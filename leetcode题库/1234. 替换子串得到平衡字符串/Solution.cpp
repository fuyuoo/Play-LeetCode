// 滑动窗口，核心是找到其中不满足的窗口，这些就是需要被替换的
class Solution {
public:
	int balancedString(string s) {
		vector<int> freq(26);
        int n = s.size();
		int target = n / 4;
		for(int i = 0 ; i < n; i++)
			freq[s[i] - 'A']++;
		int l = 0;
        int r = 0;
        int res = INT_MAX;
        while(r < n){
            freq[s[r]-'A']--;
            while(l < n && freq['Q' - 'A'] <= target && 
                        freq['W' - 'A'] <= target && 
                        freq['E' - 'A'] <= target && 
                        freq['R' - 'A'] <= target ){
                res = min(res,r - l + 1);
                freq[s[l] - 'A'] ++;
                l++;
            }
            r++;
        }
        return res;
		
	}
};