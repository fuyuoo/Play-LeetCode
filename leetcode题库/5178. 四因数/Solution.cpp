//N^2的复杂度，就是暴力破解，使用的余数相除法
class Solution {
public:
	int sumFourDivisors(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			vector<int> tmp;
			int tmpsum = 0;
			int n = nums[i];
			for (int j = 2; j < n; j++) {
				if (n % j == 0) {
					n = n / j;
					tmp.emplace_back(j);
				}
			}
			if (tmp.size() == 1)
			{
				int another = nums[i] / tmp[0];
				if (another != tmp[0])
				{
					res += (tmp[0] + another +1 + nums[i]);

				}

			}
		}
		return res;
	}
};