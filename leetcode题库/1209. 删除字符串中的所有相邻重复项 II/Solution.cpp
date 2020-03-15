class Solution {
public:
	string removeDuplicates(string s, int k) {
		stack<pair<char, int>> st;
		st.push({ s[0], 1 });
		int i = 1;
		while(i < s.size()){
			if(st.empty())
				st.push({ s[i],1 });
			else
			{
				char t = st.top().first;
				int count = st.top().second;
				if (s[i] == t)
					if (count == k - 1)
						while (count--)
							st.pop();
					else
						st.push({ s[i],count + 1 });
				else 
					st.push({ s[i],1 });
			}
			
			i++;
		}
		string res ;
		while(!st.empty())
		{
			res += st.top().first;
			st.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};