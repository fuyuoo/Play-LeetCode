// 动态规划，还是不是很会，但是今天想到的一点就是动规也是暴力，只是有记事本
// 字底向上，先解决小的，形成最优子结构，一步步扩大然后把大的破解成两个小的，看两个最优小解能否给出这个解
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(int i = 1; i < dp.size() ; i++){
            for(int coin : coins){
                if(i - coin >= 0){
                    dp[i] = min(dp[i],1 + dp[i - coin]);
                }
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};