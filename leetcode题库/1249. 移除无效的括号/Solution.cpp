// 通过匹配左边，看右边能否加入
//然后再看有没有剩余的左边，移除
class Solution {
public:
	string minRemoveToMakeValid(string s) {
		stack<char> st;
		string res;
		for (char& ch : s) {
			if (ch == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
					res += ch;
				}
			}
			else if (ch == '(') {
				res += ch;
				st.push(ch);
			}
			else {
				res += ch;
			}
		}
		int n = st.size();
		while (n > 0 ) {
			res.erase(res.begin() + res.find_last_of('('));
			n--;
		}
		return res;
	}
};