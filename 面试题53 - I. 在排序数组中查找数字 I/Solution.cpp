class Solution {
private:
    int leftBound(vector<int>& nums, int target){
        int l = 0 , r = nums.size()-1;
        while(l <= r){
            int mid = (r - l) / 2 + l;
            if(target > nums[mid]){
                l = mid + 1;
            }else if(target < nums[mid]){
                r = mid - 1;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }
    int rightBound(vector<int>& nums, int target){
        int l = 0 , r = nums.size()-1;
        while(l <= r){
            int mid = (r - l) / 2 + l;
            if(target > nums[mid]){
                l = mid + 1;
            }else if(target < nums[mid]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
public:
    int search(vector<int>& nums, int target) {
        return rightBound(nums,target) - leftBound(nums,target)+1;
    }
};