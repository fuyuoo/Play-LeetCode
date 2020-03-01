class Solution {
private:
	string topSort(unordered_map<char, vector<char>>& outdegrees, vector<int>& indegrees,set<char>& allpick) {
		queue<char> q;
		for (char t : allpick) { 		  // 通过获取到的全部元素开始遍历，入度为0的入队
			if (indegrees[t-'a'] == 0)
				q.push(t);
		}
		vector<char> charRes ;
		// 基本的拓扑排序过程
		while (!q.empty()) {
			char cur = q.front();
			charRes.emplace_back(cur);
			for (auto t : outdegrees[cur]) {
				int n = t - 'a';
				indegrees[n]--;
				if (indegrees[n] == 0) {
					q.push(char(n + 'a'));
				}
			}
			outdegrees[cur].clear();
			q.pop();
		}
		// 判断是否通过顶点能全部访问到，不能则说明有环
		if (charRes.size() != allpick.size())
			return "";
		string res(allpick.size(),' ');
		int i;
		for ( i = 0; i < charRes.size(); ++i)
		{
			res[i] = charRes[i];
		}
		
		return res;
	}
public:
	string alienOrder(vector<string>& words) {
		// 一些异常情况
		if (words.empty())
			return "";
		if (words.size() == 1)
			return words[0];
		unordered_map<char, vector<char>> outdegrees; //出度表
		vector<int> indegrees(26); 					  //入度表
		set<char> allpick;
		for (int i = 1; i < words.size(); i++) {
			string a = words[i - 1];
			string b = words[i];
			int an = a.size();
			int bn = b.size();
			int n = max(an, bn);    // 这里取最大值是为了获取全部的元素
			int found = false; 	    // 为了获取最大值，但是肯定是入度为0的点，所以不用记录
			for (int j = 0; j < n; j++) {
				char c = j < an ? a[j]:' ' ;
				char d = j < bn ? b[j]:' ' ;
				if(c!=' ')
					allpick.insert(c);
				if(d != ' ')
					allpick.insert(d);

				if (c == d) {
					continue;
				}
				else if(c != ' '&& d != ' ' && !found) {
					outdegrees[c].emplace_back(d);
					indegrees[d - 'a']++;
					found = true;
				}
			}
		}
		
		return topSort(outdegrees, indegrees,allpick);

	}
};

