// split 然后转换成Int 比较
class Solution {
private:
	vector<int> split(string& s) {
		string cur;
		vector<int> res;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') {
				res.emplace_back(stoi(cur));
				cur.clear();
			}
			else {

				cur += s[i];
			}
		}
		res.emplace_back(stoi(cur));
		return res;

	}
public:
	int compareVersion(string version1, string version2) {
		vector<int> split1 = split(version1);
		vector<int> split2 = split(version2);
		int m = split1.size();
		int n = split2.size();
		int size = max(m, n);
		for (int i = 0; i < size; i++) {
			int t1 = i >= m ? 0 : split1[i];
			int t2 = i >= n ? 0: split2[i];
			if (t1 > t2)
				return 1;
			else if (t1 < t2)
				return -1;
		}
		return 0;
	}
};