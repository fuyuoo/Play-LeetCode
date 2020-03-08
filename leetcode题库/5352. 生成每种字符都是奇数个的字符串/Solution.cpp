// 不懂出题意图，纯送分
class Solution {
public:
    string generateTheString(int n) {
        string res ;
        if(n == 0 )
            return res;
        if(n%2 == 1){
            while(n--){
                res +='a';
            }
            return res;
        }else{
            n--;
            while(n--){
                res +='a';
            }
            return res + 'b';
        }
    }
};