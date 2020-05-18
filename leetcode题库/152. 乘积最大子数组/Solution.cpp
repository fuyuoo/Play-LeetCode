class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int imax = 1;
		int imin = 1;
		int res = INT_MIN;
		for (int i = 0; i < nums.size(); i++) {
			
			// 如果当前元素为负数，则最小值可能为负数，相乘则为正数。
			if (nums[i] < 0) 
				swap(imax, imin);
			// 与新数相乘，看是否能得到更大或更小的数
			imax = max(nums[i], nums[i] * imax);
			imin = min(nums[i], nums[i] * imin);
			// 保存最大值，因为上面的交换操作，所以不会错过最大值
			res = max(res, imax);
		}
		return res;
	}
};