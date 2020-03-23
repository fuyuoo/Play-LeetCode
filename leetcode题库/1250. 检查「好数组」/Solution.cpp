// 就是看全部的最大公约数能否是1 ，如果是1则存在两两互质的最大公因数，可以使用这两个互质的公因数实现
// 如果不为1 则所有的公因数大于1  不能实现好数组
class Solution {
private:
    int gcd(int a,int b){
        return a == 0 ? b:gcd(b%a,a);
    }
public:
    bool isGoodArray(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            res = gcd(res,nums[i]);
        }
        return res == 1;
    }
};