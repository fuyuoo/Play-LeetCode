class Solution {
private:
    int cal(queue<char>& q){

        char sign = '+';
        long num = 0;
        stack<int> numstack;
        stack<char> signstack;
        while(!q.empty()){
            char cur = q.front();
            q.pop();
            if(isdigit(cur)){
                num = num * 10 + cur - '0';
            }else{
                if(!signstack.empty() && (signstack.top() == '/' || signstack.top() == '*')){
                   char t = signstack.top();
                   int prenum = numstack.top();
                   numstack.pop();
                   if(t == '/')
                    num = prenum / num;
                   else
                    num = prenum * num;
                }
                if(sign == '-')
                    num = -num;
                numstack.push(num);
                signstack.push(cur);
                if(cur == '-')
                    sign = '-';
                else
                    sign = '+';
                num = 0;
            }
        }
        int sum = 0;
        while(!numstack.empty()){
            sum += numstack.top();
            numstack.pop();

        }
        return sum;
    }
public:
    int calculate(string s) {
        queue<char> q;

        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] != ' ')
                q.push(s[i]);
        }
        q.push('+');
        return cal(q);
    }
};