/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */
// 就是暴力搜索，然后因为是单调增的，所以如果比它大就停止，剪枝
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res ;
        for(int i = 1 ; i < 1000 ; i++){
            for(int j = 1; j < 1000 ; j++){
                int target = customfunction.f(i,j);
                if(target == z)
                    res.emplace_back(vector<int>({i,j}));
                if(target > z)
                    break;
            }
        }
        return res;
    }
};