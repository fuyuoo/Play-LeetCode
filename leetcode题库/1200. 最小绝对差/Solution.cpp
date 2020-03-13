// 核心、排序
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        if(arr.size() < 2)
            return vector<vector<int>>();
        sort(arr.begin(),arr.end());
        vector<vector<int>> map;
        int minx = INT_MAX;
        for(int i = 1 ; i < arr.size(); i++){
            int x = arr[i] - arr[i-1];
            if(x < minx){
                minx = x;
                map.clear();
                map.emplace_back(vector<int>({arr[i-1] , arr[i]}));
            }else if (x == minx)
                map.emplace_back(vector<int>({arr[i-1] , arr[i]}));
        }

        return map;
    }
};