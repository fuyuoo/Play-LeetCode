class Solution {
public:
    int nthUglyNumber(int n) {
        int a =0,b=0,c=0;
        vector<int> memo(n);
        memo[0] = 1;
        for(int i = 1 ; i < memo.size() ; i++){
            int tmp = min(min(memo[a] * 2,memo[b]*3),memo[c] * 5);
            memo[i] = tmp;
            if(tmp == memo[a] * 2)
                a++;
            if(tmp == memo[b] * 3)
                b++;
            if(tmp == memo[c] * 5)
                c++;
        }
        return memo[n-1];

    }
};