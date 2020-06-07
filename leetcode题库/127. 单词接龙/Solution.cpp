class Solution {
public:

	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

		unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.count(endWord)  == 0) return 0;
        wordSet.erase(endWord);
        int step = 2;
        unordered_set<string> head{beginWord},tail{endWord};

        while(head.size() > 0 && tail.size() > 0){
			// 双向寻找，从少的开始找，因为是转换，所以顺序可以反转
            if(head.size() > tail.size())
                swap(head,tail);
			// 存储的是下一组可以转换的单词
            unordered_set<string> tmp;
            for(string word : head){
                for(int i = 0 ; i < word.size() ; i++){
                    char ch = word[i];
					// 逐字比较，是否有相差一个且在字典中的单词，有则表面可以转换
                    for(int j  = 'a' ; j <= 'z' ; j++){
                        if(j == ch) continue;
                        word[i] = j;
						// 如果能匹配到结束的单词了则停止
                        if(tail.count(word) > 0)
                            return step;
                        else if(wordSet.count(word)){
                            wordSet.erase(word);
                            tmp.insert(word);
                        }
                    }
                    word[i] = ch;
                }
            }
            swap(tmp,head);
			// 使用的是bfs，每次所有行为都往前走一步
            step++;
        }

		return 0;
	}

};