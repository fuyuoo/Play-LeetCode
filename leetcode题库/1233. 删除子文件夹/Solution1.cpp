// 先排序，这样就会按字典序排好
// l代表头文件夹，r代表是否构成子文件夹
class Solution {
private:
	bool ispre(string& s1,string& s2){
		if(s1.size() == s2.size()) return false;
		int i = 0;
		for( ; i < s1.size() ; i++){
			if(s1[i] != s2[i]) return false;
		}
		// 因为s1是肯定更短的，如果到了这一步，否则前面就已经不满足了
		return s2[i] == '/';
	}
public:
	vector<string> removeSubfolders(vector<string>& folder) {
		sort(folder.begin(), folder.end());
		vector<string> res;
		int l = 0;
		int r = 1;
		int n = folder.size();
		res.emplace_back(folder[0]);

		while(l < n && r < n){
			// 如果是前缀则跳过
			if(ispre(folder[l], folder[r])){
				r++;
			// 如果不满足，进入结果，然后按这个来找
			}else{
				l = r;
				r ++;
				res.emplace_back(folder[l]);
			}
		}
		return res;
	}
};