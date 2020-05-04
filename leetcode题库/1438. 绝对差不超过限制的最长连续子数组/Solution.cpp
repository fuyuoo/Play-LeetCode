// 滑动窗口
// 一直监听区间内最大最小值，如果差值没有超出范围，则右边扩张
// 如果超出范围了，则从右边段重新开始，重置最大最小值和长度
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0;
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        int length = 0;
        int l = 0;
        int r = 0;
        while(r < nums.size()){
            minNum = min(minNum,nums[r]);
            maxNum = max(maxNum,nums[r]);
            if(maxNum - minNum > limit){
                minNum = INT_MAX;
                maxNum = INT_MIN;
                l++;
                r = l;
                length = 0;
            }else{
                r++;
                length++;
                res = max(length,res);
            }
        }
        return res;
        
    }
};