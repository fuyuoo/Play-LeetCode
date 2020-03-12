// 类似于运算符的括号
class Solution {
private:
    string helper(queue<char>& q){
        string cur ;
        string res ;
        while(!q.empty()){
            char t = q.front();
            q.pop();
            if(t == '('){
				string tmp = helper(q);
				reverse(tmp.begin(), tmp.end());
				res += tmp;
            }else if(t == ')')
                break;
            else{
                res += t;
            }
        }
        return res;
        
    }
public:
    string reverseParentheses(string s) {
        queue<char> q;
        for(int i = 0 ; i < s.size() ;i++){
            q.push(s[i]);
        }
        return helper(q);
    }
};