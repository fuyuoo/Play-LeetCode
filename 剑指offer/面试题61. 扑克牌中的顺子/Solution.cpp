// 先排序，然后得到0的个数，看offset与0的比较结果
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zeroindex =  0;
        for(int i = 0 ; i < nums.size() ; i ++){
            if(nums[i] == 0) zeroindex++;
        }
        int offset = 0;
        for(int i = zeroindex ; i < nums.size()-1 ; i++){
            int t = nums[i+1] - nums[i];
            if(!t)
                return false;
            else
                offset += (t - 1);
        }
        return zeroindex >= offset;

    }
};