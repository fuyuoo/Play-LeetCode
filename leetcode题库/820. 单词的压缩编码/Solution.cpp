// 前缀树，但是因为是从后面看是否重叠，所以倒叙插入，很关键
struct Tree {
	unordered_map<char, Tree*> children;
	Tree() = default;
};

class PreNode {
	Tree* node;
public:
	PreNode() {
		node = new Tree();
	}
	
	int insert(string str) {
		Tree* p = node;
		bool isNew = false;
		for (int i = str.size() - 1; i >= 0; i--) {
			char w = str[i];
			if (p->children.find(w) == p->children.end())
			{
				p->children[w] = new Tree();
				isNew = true;
			}
			p = p->children[w];
		}
		return isNew ? str.size() + 1 : 0;

	}
};

class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		sort(words.begin(), words.end(), [](string& str1, string& str2)
			{
				return str1.size() > str2.size();
			});
		PreNode node;
		int res = 0;
		for (string& str : words) {
			res += node.insert(str);
		}
		return res;
	}
};