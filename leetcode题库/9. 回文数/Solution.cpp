class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        long res = 0;
        int xx = x;
        while(x){
            res  = res *10 + x % 10;
            x /=10;
        }
        return xx == res;
    }
};