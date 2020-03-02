// 没有乘除，直接得到结果放入结果栈中
// 关键就是括号其实就是另一个，所以用递归解决
class Solution {
private:
	int cal(queue<char>& q) {

		stack<int> s;
		long num = 0;
		int sum = 0;

		char sign = '+';
		
		while (!q.empty()) {
			char t = q.front();
			q.pop();
			if (isdigit(t)) {
				num = num * 10 + t - '0';
			}
			else if (t == '+' || t == '-') {
				if (sign == '+')
					s.push(num);
				else if (sign == '-')
					s.push(-num);
				sign = t;
				num = 0;
			}
			else if (t == '(') {
				if (sign == '+')
					s.push(cal(q));
				else if (sign == '-')
					s.push(-cal(q));
			}
			else if (t == ')') {
				break;
			}
		}
		while (!s.empty()) {
			sum += s.top();
			s.pop();
		}
		return sum;
	}
public:
	int calculate(string s) {
		queue<char> q;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ')')
				q.push('+');
			if (s[i] != ' ')
				q.push(s[i]);
		}
		q.push('+');

		return cal(q);
	}
};