class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int n = strs.size();
		if (n == 0)
			return "";
		for (int i = 0; i < strs[0].size(); i++) {
			char t = strs[0][i];
			for (int j = 1; j < n; j++) {
				if (i == strs[j].size() || strs[j][i] != t)
					return strs[0].substr(0, i);
			}
		}
		return strs[0];
	}
};