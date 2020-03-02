// 使用哈希表O(n)
// 还可以先排序然后找到中间的数就可以 O（nlogN）
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size() / 2;
        for(int i : nums){
            map[i]++;
            if(map[i] > n)
                return i;
        }
        return -1;
    }
};
