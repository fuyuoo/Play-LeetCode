// 纯粹利用hashmap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size() / 2;
        for(int t : nums){
            map[t]++;
            if(map[t] > n)
                return t;
        }
        return -1;
    }
};