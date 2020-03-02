// 使用因为是得到符号了再进行计算，所以处理后的数据最后要加一个'+'
// 然后因为有* / 优先级，所以需要放入栈中，如果栈顶是优先级高的就直接计算，然后放进去
// 最后储存的是所有的数，再相加
// 有个细节就是除了- 其他的数都是正数
class Solution
{
private:
	int cal(queue<char>& q)
	{
		stack<int> numstack;
		stack<char> signstack;
		char sign = '+';
		long num = 0;
		while (!q.empty())
		{
			char t = q.front();
			q.pop();
			if (isdigit(t))
			{
				num = num * 10 + t - '0';
			}
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
				if (sign == '-')
					num = -num;
				signstack.push(t);
				numstack.push(num);
				num = 0;
				if (t == '-')
					sign = t;
				else
					sign = '+';
			}
		}
		int sum = 0;
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
			if (s[i] != ' ')
				q.push(s[i]);
		}
		q.push('+');
		return cal(q);
	}
};
