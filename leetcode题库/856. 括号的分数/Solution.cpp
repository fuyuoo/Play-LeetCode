// 每看到一个左括号则深度加一
// 看到右括号时，匹配到了，深度减一，如果之前还是左括号，然后分数通过深度计算，分数是 2^(level)
// 然后把个个括号的加起来
class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0;
        int level = 0;
        for(int i = 0 ; i < S.size() ; i++){
            if(S[i] == '(')
                level ++;
            else{
                level--;
                if(S[i-1] == '(')
                    res += 1 << level;
            }
        }
        return res;
    }
};