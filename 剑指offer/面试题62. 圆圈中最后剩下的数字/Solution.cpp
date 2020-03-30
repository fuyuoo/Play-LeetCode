// 约瑟夫环问题，每次去除一个然后从0开始数，可以相当于全部的往前移动n位
class Solution {
public:
    int lastRemaining(int n, int m) {
        int res = 0;
        for(int i = 2 ; i <= n ; i++){
            res = (res + m) %i;
        }
        return res;
    }
};