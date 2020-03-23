// 可以使用滑动窗口，满足条件之后，每次右边动，加上index + id
// 这个思路就是前缀奇数个数，然后因为你要K个奇数，看当前的奇数减去你要的奇数，这样的个数有多少个，加起来 two sum
class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		vector<int> arr;
		int res = 0;
		arr.emplace_back(0);
		for(int t:nums)
			arr.emplace_back(arr.back() + (t & 1));
		unordered_map<int, int> h;
		for (int t : arr)
		{
			res += h[t - k];
			h[t]++;
		}
		return res;

	}
};