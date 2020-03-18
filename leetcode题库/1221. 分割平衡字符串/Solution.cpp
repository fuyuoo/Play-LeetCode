// 记录字频，因为数量要相同，所以一个加一一个减一， 0则相同，然后每次相同就记录一下
class Solution {
public:
    int balancedStringSplit(string s) {
        int num = 0;
        int res = 0;
        for(int i = 0 ; i < s.size() ; i ++){
            if(s[i] == 'L')
               num ++;
            else
                num--;
            if(num == 0)
                res ++;
        }
        return res;
    }
};