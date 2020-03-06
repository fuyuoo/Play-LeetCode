// 通过栈，其实和前面那个差不多，只是每次计算之后用栈存储了
// 遇到左括号，入栈“0”,
// 遇到右括号，把前两个都出栈，把前一个乘2 加上前一个再入队，因为每次肯定满足一个，所以最小值为1
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        s.push(0);
        for(char t : S){
            if(t == '(')
                s.push(0);
            else{
                int w = s.top();
                s.pop();
                int v = s.top();
                s.pop();
                s.push( v + max(2 * w ,1));
            }
        }
        return s.top();
    }
};