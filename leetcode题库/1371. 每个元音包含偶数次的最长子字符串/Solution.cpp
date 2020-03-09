class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> record(32,INT_MAX);
        record[0]  = -1;
        int ans = 0;
        int cur = 0;
        
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'a')
                cur ^= 1;
            else if(s[i] == 'e')
                cur ^= 2;
            else if(s[i] == 'i')
                cur ^= 4;
            else if(s[i] == 'o')
                cur ^= 8;
            else if(s[i] == 'u')
                cur ^= 16;
            if(record[cur] == INT_MAX)
                record[cur] = i;
            else{
                ans = max(ans, i - record[cur]);
            }
        }
        return ans;
    }
};