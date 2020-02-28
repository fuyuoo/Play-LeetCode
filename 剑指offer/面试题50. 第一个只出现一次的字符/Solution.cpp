class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> cache(26);
        for(char t : s){
            cache[t - 'a'] ++;
        }
        for(char t : s){
            if(cache[t - 'a'] == 1)
                return t;
        }
        return ' ';
    }
};