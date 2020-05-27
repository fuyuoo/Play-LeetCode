// 利用前缀和计算，因为如果是相同的余数，则表明如果两个数组减去余数部分，则可以构成，在后面再次得到相同余数则要把之前的加上，因为这些之间可以进行排列组合
// 比如数组 4 5 6 5 6 
// 对11 取模，在位置2 和4 、的位置的前缀和取模是一样的，
// 只要去掉相同的一部分剩余部分的两个数组的取模是一样的
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int count = 0;
        int presum = 0;
        vector<int> map(K,0);
        map[0] = 1;
        for(int i = 0 ; i < A.size() ; i++){
            presum  = (presum + A[i]) % K;
            if(presum < 0)
                presum += K;
            if(map[presum] != 0)
                count += map[presum];
            map[presum]++;
        }
        return count;
    }
};