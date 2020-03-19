class Solution {
private:
	// 看按这个甜度能分多少份，能不能分出指定人数多的份
    bool helper(int mid,int K,vector<int>& sweetness){
        int sum = 0;
        for(int sweet : sweetness){
            if(sum >= mid){
                K--,sum = sweet;
            }else{
                sum += sweet;
            }
        }
        return K < 0 || (K == 0 &&(sum == 0 || sum >= mid)); 
    }
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int l = 0 ;
        int r = INT_MAX;
		// 因为是最小的，所以肯定只有一份，然后找到这一份
        while(l != r){
            if(l + 1 == r){  // 临界，看哪个满足
                if(helper(r,K,sweetness)){  
                    l = r;
                }else{
                    r = l;
                }
            }
            int mid = l + (r - l) / 2;
            if(helper(mid,K,sweetness)){
                l = mid ;   // 能分完，然后尝试更大的甜度
            }else{
                r = mid - 1;  // 不能分出来，找更小的甜度
            }
        }
        return l;
    }
};