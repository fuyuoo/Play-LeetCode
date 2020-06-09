class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int dp[11];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < str.size(); i ++) {
            if(str[i-1] =='0' || stoi(str.substr(i-1,2)) > 25 ){
                dp[i+1] = dp[i];
            }else{
                dp[i+1] = dp[i] + dp[i-1];
            }
        }
		
        return dp[str.size()];
    }
};
