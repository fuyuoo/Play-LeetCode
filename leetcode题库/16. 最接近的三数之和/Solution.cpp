// 和三数之和差不多
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int minoffset = INT_MAX;
        int res = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            int l = i+1 ;
            int r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target)
                    return target;
                int offset = target - sum;
                if(abs(offset) < minoffset){
                    res = sum;
                    minoffset = abs(offset);
                }else if(l < r && offset > 0)
                    l++;
                else if(l < r && offset < 0)
                    r--;
            }


        }
        return res;
    }
};