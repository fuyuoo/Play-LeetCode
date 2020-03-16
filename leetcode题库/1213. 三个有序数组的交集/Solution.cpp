// 字频统计，这个算法如果单个数组有重复就没用了
// 但是没有利用递增性质
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        unordered_map<int,int> map;
        for(int i = 0 ; i < arr1.size();i++){
            map[arr1[i]]++;
            map[arr2[i]]++;
            map[arr3[i]]++;
        }
        vector<int> res;
        for(int i = 0 ; i < arr1.size();i++){
            if(map[arr1[i]] == 3)
                res.emplace_back(arr1[i]);
        }
        return res;
    }
};