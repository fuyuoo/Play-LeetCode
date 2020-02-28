class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> res(n,1);
        for(int i = 1 ; i < n ; i++){
            res[i] *= res[i-1] * a[i - 1];
        }
        int tmp = 1;
        for(int i = n-2;i >= 0 ; i--){
            tmp *= a[i+1];
            res[i] *= tmp;
        }
        return res;

    }
};