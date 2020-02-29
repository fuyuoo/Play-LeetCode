class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0 , r = nums.size() - 1;
        while(l <= r){
            int mid = (r - l) / 2 + l;
            if(mid != nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};