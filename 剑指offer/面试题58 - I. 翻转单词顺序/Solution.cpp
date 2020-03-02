// 就只需要注意空格就好了
class Solution {
private:
	list<string> mysplit(string& s, char t) {
		string cur;
		list<string> res;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == t) {
				if (!cur.empty()) {
					res.emplace_front(cur);
					cur = "";
				}
			}
			else {
				cur += s[i];
			}
		}
		if(!cur.empty())
			res.emplace_front(cur);
		return res;
	}
public:
	string reverseWords(string s) {
		list<string> splits = mysplit(s, ' ');
		string res;
		for (string cur : splits) {
			res += cur + " ";
		}
		res.erase(res.end() - 1);
		return res;
	}
};