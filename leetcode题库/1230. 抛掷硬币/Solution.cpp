// dp
// i代表几个硬币，j代表几个正面
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> dp(n+1,vector<double>(vector<double>(target+2)));
        dp[0][0] = 1;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j <= i && j <= target ; j++){
                dp[i+1][j+1] += dp[i][j] * prob[i];
                dp[i+1][j]  += dp[i][j] * (1-prob[i]);

            }
        }
        return dp[n][target];
    }
};