// 还以为求最长回文子序列
// 其实这个string 变成vector<char> 题意更好一些
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cache(256);
        int count = 0;
        for(char t : s){
            cache[t]++;
            if(cache[t] % 2 == 0)
                count +=2;
        }
        if(count == s.size()) return count;
        return count + 1;
    }
};