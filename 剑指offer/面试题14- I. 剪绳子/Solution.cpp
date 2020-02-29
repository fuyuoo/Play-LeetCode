class Solution {
private:
    vector<int> cache;
    int helper(int n){
        if(n == 2)
            return 1;
        if(cache[n] != -1)
            return cache[n];
        int res = -1;
        for(int i = 1 ; i < n ; i++){
            res = max(res, max(i * (n - i) , helper(n-i) * i));
        }
        return cache[n] = res;
    }
public:
    int cuttingRope(int n) {
        cache = vector<int>(n+1,-1);
        
        return helper(n);
        
    }
};