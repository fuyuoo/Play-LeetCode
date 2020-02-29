// 也可以使用哈希表，但是好像慢很多
// 就是标记字符是否被访问过了，如果被访问了，则前一个标记点一直往后找，直到没有重复的
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cache(256,0);
        int j = 0;
        int maxLen = 0;
        for(int i = 0 ; i < s.size() ; i++){
            int n = s[i] ;
            cache[n]++;
            while(cache[n]>1){
                cache[s[j]] --;
                j++;
            }
            maxLen = max(maxLen,i - j + 1);

        }
        return maxLen;
    }
};