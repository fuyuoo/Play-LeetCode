// 等差数列求和公式，(a1+an) * n / 2
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int t: arr){
            sum += t;
        }
        int targetSum = (arr[0]  + arr[n-1]) * (n+1) / 2;
        return targetSum - sum;
    }
};