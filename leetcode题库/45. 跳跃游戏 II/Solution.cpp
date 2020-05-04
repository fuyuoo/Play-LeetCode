class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int reach = 0;	// 目标点
        int nextreach = nums[0]; // 最长的目标点
        int step = 0; //跳跃次数
        for(int i = 0 ; i < nums.size() ; i++){
            nextreach = max(nextreach,i + nums[i]);
            if(nextreach >= n-1) 
                return step + 1;
            if(i == reach){    // 如果到达了前一个段的最远步长点，把期间得到的最长的步长进行覆盖，贪心算法
                step ++;
                reach = nextreach;
            }
        }
        return step;
    }
};