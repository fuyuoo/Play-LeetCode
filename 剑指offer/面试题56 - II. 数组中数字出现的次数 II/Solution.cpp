class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> cache;
        for(int t:nums){
            cache[t]++;
        }
        for(int t:nums){
            if(cache[t] == 1) return t;
        }
        return -1;
    }
};