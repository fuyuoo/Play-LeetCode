// 背题+1
// 个数有2^n次方个
//每次就是个数和个数的一半的异或
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i = 0 ; i < 1 << n ; i++){
            res.emplace_back(i ^ i / 2);
        }
        return res;
    } 
};