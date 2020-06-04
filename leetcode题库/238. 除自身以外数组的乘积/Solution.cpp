
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int k = 1;
        int n = nums.size();
        vector<int> res(n);
        for(int  i = 0 ; i < n ; i++){
            res[i] = k;
            k *= nums[i];
        }
        k = 1;
        for(int i = n -1 ; i >=0 ; i--){
            res[i] *= k;
            k *= nums[i]; 
        }
        return res;
    }
};