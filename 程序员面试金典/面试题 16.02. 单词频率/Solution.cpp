// 纯粹是考哈希
class WordsFrequency {
private:
    unordered_map<string,int> map;
public:
    WordsFrequency(vector<string>& book) {
        for(string t : book){
            map[t] ++;
        }
    }
    
    int get(string word) {
        return map[word];
    }
};