// 一开始想用前缀树，后面发现好像也没用，因为要找到几个字母共同的，
// 可以是可以用但是时间复杂度很大
// 这个算法的思路就是，先统计所有B的字母字频
// 然后在每一个A的单词中，先统计这个单词的字母字频，然后看这个每个单词的字频是否小于等于B的字频
// 如果小于则B可以构成这个单词
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> maxcount(26);
        for(string& t:B){
            vector<int> tmp(26);
            for(char t1 : t){
                tmp[t1-'a']++;
                maxcount[t1-'a'] = max(maxcount[t1-'a'],tmp[t1-'a']);
            }
        }
        vector<string> res;
        for(string& t:A){
            vector<int> tmp(26);
            for(char t1 : t){
                tmp[t1-'a']++;
            }
            bool flag = true;
            for(int i = 0 ; i < 26 ; i++){
                if(tmp[i] < maxcount[i]){
                    flag = false;
                    break;
                }
            }
            if(flag) res.emplace_back(t);
        }
        return res;
    }
};