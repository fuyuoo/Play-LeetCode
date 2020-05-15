// 使用一个哈希表存储在这个点之前可达到的值。每次寻找都寻找当前值和目标值的差值，如果有则表明正好等于K，说明减去前面的某一段之后，和为k
// 类似于两数之和的解法
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0] = 1;
        int res = 0;
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            if(map.find(sum - k) != map.end())
                res += map[sum-k];
            map[sum]++;
        }
        return res;
    }
};