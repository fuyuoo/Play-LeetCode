
class Solution {
private:
	int getN(int l,int r){
		
		if(l > r) return 1;
		int sum = 0 ;
		for(int i = l ; i <= r ; i++)
			sum += (getN(l,i-1) * getN(i+1,r));
		
		return sum;
	}
public:
	int numTrees(int n) {
		
		if(n == 0) return 0;
		return getN(1,n);
	}

};
