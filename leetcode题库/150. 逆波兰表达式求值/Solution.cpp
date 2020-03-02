// 最想的就是通过char的运算符直接计算就好了
// 其他的没什么，就是后缀表达式计算
class Solution {
private:
    void cal(stack<int>& num,char sign){

            int pre = num.top();
            num.pop();
            int cur = num.top();
            num.pop();
            if(sign == '+')
                num.push(cur + pre);
            else if (sign == '-')
                num.push(cur - pre);
            else if (sign == '/')
                num.push(cur / pre);
            else if (sign == '*')
                num.push(cur * pre);
    }           
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for(int i = 0 ; i < tokens.size() ; i++){

            if(tokens[i] == "+" || tokens[i] == "-"|| tokens[i] == "*"|| tokens[i] == "/"){
                cal(num, tokens[i][0]);
            }else{
                num.push(stoi(tokens[i]));
            }
        }
        return num.top();
    }
};