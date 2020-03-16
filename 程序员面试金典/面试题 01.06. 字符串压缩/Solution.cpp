// 记录字母次数
class Solution {
public:
    string compressString(string S) {
        string res;
        char t = S[0];;
        int count = 1;
        for(int i = 1 ; i < S.size() ; i++){
            if(S[i] == t)
                count++;
            else{
                res += t +to_string(count);
                t = S[i];
                count = 1;
            }
        }
        res += t + to_string(count);
        return res.size() < S.size()?res:S;
    }
};