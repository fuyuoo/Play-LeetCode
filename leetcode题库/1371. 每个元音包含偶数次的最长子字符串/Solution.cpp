// 关键点，记录每次当前的状态，如果没出现过则记录下来，出现过则表明两个状态在不同位置都出现过，则又表明这两个状态之间的字符肯定满足都为偶数的条件
// 使用状态压缩把状态进行保存，如果数字不方便用数组也可以使用哈希表保存
class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> record(32,INT_MAX);
        record[0]  = -1; // 初始化为-1是为了记录最开始全0的状态
        int ans = 0;
        int cur = 0;  // 使用每一位来确定当前元音是否为偶数
        
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