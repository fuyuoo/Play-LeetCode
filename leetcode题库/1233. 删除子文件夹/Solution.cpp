// 前缀树
struct PreTree {
	bool isEnd;
	unordered_map<string, PreTree*> childern;
	PreTree() {
		isEnd = false;
	}
};
class Solution {
private:
	vector<string> split(const string& str, const char& delim)
	{
		vector<string> res;
		if ("" == str) return res;
		string cur;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == delim)
			{
				res.push_back(cur);
				cur = "";
			}
			else
				cur += str[i];
		}
		res.push_back(cur);

		return res;
	}
public:
	vector<string> removeSubfolders(vector<string>& folder) {
		sort(folder.begin(), folder.end());
		PreTree* root = new PreTree();
		char sp = '/';
		vector<string> res;
		for (string& t : folder) {
			PreTree* p = root;
			vector<string> splits = split(t, sp);
			bool flag = true;
			for(string& fol : splits)
			{
				if (p->isEnd == true)
					flag = false;
				if(p->childern.find(fol) == p->childern.end())
				{
					p->childern[fol] = new PreTree();
				}
				p = p->childern[fol];

			}
			p->isEnd = true;
			if (flag)
			{
				res.emplace_back(t);
			}
		}
		return res;
	}
};