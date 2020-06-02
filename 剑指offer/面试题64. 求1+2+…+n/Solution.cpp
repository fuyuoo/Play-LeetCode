// 使用短路来作为递归的终止条件
class Solution {
public:
    int sumNums(int n) {
        int sum = 0;

        bool f = (n > 0 ) && (sum = n +sumNums(n-1));
        return sum;
    }
};