// 直译题目
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int preOne = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 1){
                if(preOne != -1){
                    int offset = i - preOne;
                    if(offset <= k)
                        return false;
                }
                preOne = i;
            }
        }
        return true;
    }
};