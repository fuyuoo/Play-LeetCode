// 昨天未完成，今天做好了，算是今天最大的收获，因为思路虽然是提供的，但是代码和优化都自己写的，和比人给的题解差不多，几乎是最优解
// 使用快速选择排序，返回基准值，如果基准值等于k值，也就是第k大元素
// 因为是快速选择排序，所以可以剪枝，通过判断基准值和k的大小关系，确定在基准值的左边还是右边
class Solution {
private:
	int partition(vector<int>& nums, int l, int r)
	{
		int randnum = rand() %(r - l+1) + l;
		int target = nums[randnum];
		swap(nums[l], nums[randnum]);
		while (l < r) {
			while (l < r && nums[r] > target)
				r--;
			nums[l] = nums[r];
			while (l < r && nums[l] <= target)
				l++;
			nums[r] = nums[l];
		}
		nums[l] = target;
		return l;
	}

public:
	int findKthLargest(vector<int>& nums, int k) {
		int m = nums.size();
		k = m - k;
		int l = 0 , r = nums.size() - 1;
		while( l <= r){
			int t = partition(nums,l,r);
			if(t == k)
				return nums[k];
			else if(t > k)
				r = t - 1;
			else
				l = t + 1;
		}
		return nums[k];
	}
};