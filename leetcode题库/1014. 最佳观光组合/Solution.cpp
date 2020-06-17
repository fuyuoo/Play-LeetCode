// 把 A[i] + A[j] + i - j ,转换成  A[i] + i   和 A[j] - j  ，求两者的最大值
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int left = A[0];
        int res = INT_MIN;
        for(int i = 1 ; i < A.size() ; i++){
            res = max(res,left + A[i] - i);
            left = max(left,A[i] + i );
        }
        return res;
    }
};