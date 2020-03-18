// 记录窗口的字频，得到窗口的最大字频
// 如果窗口内的元素比最大字频个数加上可以改变元素还大，则左边往里缩直到满足
// 总体思路就是每次都找字频最多的元素，看他在当前位置能搞几个元素
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> letters(26);
        int maxCount = 0;
        int res = 0;
        int l = 0;
        for(int i = 0 ; i < s.size() ; i++){
            char t = s[i] - 'A';
            letters[t]++;
            maxCount = max(maxCount, letters[t]);
            while(i - maxCount - k + 1 > l ){
                letters[s[l] - 'A'] -- ;
                l++;
            }
            res = max(res, i - l + 1);
            
        }
        return res;
    }
};