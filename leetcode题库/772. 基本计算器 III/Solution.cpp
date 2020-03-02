// 在Ⅱ的基础上加括号，也就是加个递归 O(N)
class Solution
{
private:
	int cal(queue<char>& q)
	{
		stack<int> numstack;
		stack<char> signstack;
		char sign = '+';
		long num = 0;
		int sum = 0;
		while (!q.empty())
		{
			char t = q.front();
			q.pop();
			if (isdigit(t))
				num = num * 10 + t - '0';
			else if (t == '*' || t == '/' || t == '+' || t == '-')
			{
				if (!signstack.empty())
				{
					char tsign = signstack.top();
					if (tsign == '/')
					{
						num = numstack.top() / num;
						numstack.pop();
					}
					else if (tsign == '*')
					{
						num = numstack.top() * num;
						numstack.pop();
					}
				}
				signstack.push(t);

				if (sign == '-')
				{
					num = -num;
				}
				numstack.push(num);
				num = 0;
				if (t == '-')
					sign = t;
				else
					sign = '+';
			}else if(t == '(')
			{
				numstack.push(cal(q));
				if(!numstack.empty())
				{
					num = numstack.top();
					numstack.pop();

				}
			}else if(t == ')')
				break;
		}
		while (!numstack.empty())
		{
			sum += numstack.top();
			numstack.pop();
		}
		return sum;
	}

public:
	int calculate(string s)
	{
		queue<char> q;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ')')
				q.push('+');
			if (s[i] != ' ')
				q.push(s[i]);
		}
		q.push('+');
		return cal(q);
	}
};