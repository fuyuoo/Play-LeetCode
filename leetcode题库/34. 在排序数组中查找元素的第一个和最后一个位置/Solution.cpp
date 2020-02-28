
// 二分法找到左边界和右边界
class Solution {
    int leftBound(vector<int>& nums, int target){
        int l = 0 , r = nums.size() - 1;
        while(l <= r){
            int mid = (r - l) / 2 + l;
            if(target > nums[mid]){
                l  = mid + 1;
            }else if(target < nums[mid]){
                r = mid - 1;
            }else{
                r = mid - 1;
            }
        }
        if( l < 0 || l >= nums.size() || nums[l] != target )
            return -1;
        return  l ;
    }
    int rightBound(vector<int>& nums, int target){
        int l = 0 , r = nums.size() - 1;
        while(l <= r){
            int mid = (r - l) / 2 + l;
            if(target > nums[mid]){
                l  = mid + 1;
            }else if(target < nums[mid]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        if( r < 0 || r >=nums.size()|| nums[r] != target)
            return -1;
        return r;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size())
            return {-1,-1};
        return {leftBound(nums, target),rightBound(nums, target)};
    }
};