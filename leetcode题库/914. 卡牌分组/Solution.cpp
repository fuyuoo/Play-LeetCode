// 核心就是求最大公约数
// 辗转相除法
class Solution {
private:
    int gcd(int x,int y){
        return x == 0 ? y : gcd(y%x,x);
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> map;
        for(int i:deck)
            map[i]++;
        int g = map[deck[0]];
        for(int i = 1; i < deck.size() ;i++){
            g = gcd(g,map[deck[i]]);
        }
        return g >= 2;
        
    }
};