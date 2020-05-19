// 感觉现在递归用的很熟练，自己直接写出来的解和别人评论高赞的一样
class Solution {
private:
    bool helper(string s,int l,int r,int t){

        while(l < r){
            if(s[l] != s[r]){
                if(t == 0) return false;
                else{
                    return helper(s,l+1,r,t-1) || helper(s,l,r-1,t-1);
                }
            }
            l++;
            r--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        
        return helper(s,0,s.size()-1,1);
    }
};