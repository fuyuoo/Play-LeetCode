class Solution {
private:
    vector<string> res;
    void helper(string cur,int l,int r,int& n){
        if(l < r)
            return ;
        if(l == n && r == n){
            res.emplace_back(cur);
            return;
        }
        if(l < n){
            helper(cur + "(", l + 1, r, n);
        }
        if(r < l){
            helper(cur + ")",l,r + 1, n);
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        helper("", 0, 0, n);
        return res;
    }
};