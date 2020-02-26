class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0 ,r = nums.size() - 1;
        int sum  = 0;
        while(sum != target){

            sum = nums[l] + nums[r];
            if(target < sum){
                r--;
            }else if(target > sum){
                l++;
            }else{
                return {nums[l],nums[r]};
            }
        }
        return {};
    }
};