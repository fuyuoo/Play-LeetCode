// 递归写法
class Solution {
private:
    bool helper(string& s,int m,string& p,int n){
        if(m == s.size()) return no_more_match(p,n);
        if(n == p.size()) return false;

        if(n + 1 < p.size() && p[n+1] == '*'){
            if(s[m] == p[n] || p[n] == '.'){
                return helper(s, m+1, p, n) || helper(s, m, p, n+2);
            }else
                return helper(s, m, p, n+2);
        }
        if(s[m] == p[n] || p[n] == '.')
            return helper(s, m+1, p, n+1);
        return false;
    }
    bool no_more_match(string& p,int n){
        int i;
        for(i = n ; i < p.size() ; i+=2){
            if(i + 1 < p.size() && p[i+1] != '*')
                return false;
        }
        return i == p.size();
    }
public:
    bool isMatch(string s, string p) {
        return helper(s, 0, p, 0);
    }
};