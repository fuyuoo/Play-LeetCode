// 短板效应
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if(text.size() < 7)
            return 0;
        vector<int> d(5);
        for(char t : text){
            if(t == 'b')
                d[0]++;
            else if(t == 'a')
                d[1]++;
            else if(t == 'l')
                d[2]++;
            else if(t == 'o')
                d[3]++;
            else if(t == 'n')
                d[4]++;
        }
        d[2]/=2;
        d[3]/=2;
        int res = INT_MAX;
        for(int t:d){
            res = min(res,t);
        }
        return res;
    }
};