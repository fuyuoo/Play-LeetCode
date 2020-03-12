// 那个!= 很厉害
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum  = 0;
        for(int t : A){
            sum+=t;
        }
        if(sum % 3 != 0)
            return false;
        int l = 0;
        int r = A.size() - 1;
        int lsum = A[0];
        int rsum = A[r];
        int target = sum / 3;
        while(l + 1 < r){
            if(lsum == target && rsum == target)
                return true;
			if (lsum != target)
				lsum += A[++l];

			if (rsum != target)
				rsum += A[--r];
            
        }
        return false;
    }
};