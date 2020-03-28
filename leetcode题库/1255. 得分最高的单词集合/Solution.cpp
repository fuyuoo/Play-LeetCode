class Solution {
public:
	int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
		vector<int> freq(26);
		// 词频统计
		for (char& t : letters)
			freq[t - 'a']++;
		return helper(0,freq,words,letters,score);
	}
	int helper(int index, vector<int>& freq, vector<string>& words, vector<char>& letters, vector<int>& score)
	{
		if (index >= words.size())
			return 0;
		vector<int> copy(freq);
		// 计算当前能否拼成
		int ret = spellWord(words[index], freq, score);
		// 如果可以，按这个递归下去，词频接着用
		int leftret = ret == 0 ? 0 : ret + helper(index + 1, freq, words, letters, score);
		// 或者不用这个，而是跳过这个，所以词频的副本
		int rightret = helper(index + 1, copy, words, letters, score);
		return max(leftret, rightret);
		
		
	}
	// 计算分数
	int spellWord(string word, vector<int>& freq, vector<int>& score)
	{
		int res = 0;
		for(char& ch : word)
		{
			int t = ch - 'a';
			if (freq[t] <= 0)
				return 0;
			res += score[t];
			freq[t]--;
		}
		return res;
	}
};