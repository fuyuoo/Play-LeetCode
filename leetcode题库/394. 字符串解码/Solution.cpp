// 类似于解析运算表达式的括号乘法
// 队列的数据结构也可以使用流实现
class Solution {
private:
	string _decode(queue<char>& q) {
		string res;
		string tmp;
		int times = 0;
		while (!q.empty()) {
			char ch = q.front();
			q.pop();
			if (isdigit(ch)) {
				times = times * 10 +  ch - '0';
			}
			else if (ch == '[')
			{
				string t = _decode(q);
				for (int i = 0; i < times; i++)
					tmp += t;
				times = 0;
			}
			else if (ch == ']') {
				break;
			}
			else {
				tmp += ch;
			}

		}
		return res + tmp;
	}
public:
	string decodeString(string s) {
		queue<char> q;
		for (char ch : s) {
			q.push(ch);
		}
		return _decode(q);
	}
};