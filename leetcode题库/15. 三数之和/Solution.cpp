class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ret;
		// 从小到大排序
		sort(nums.begin(), nums.end());

		if (nums.size() < 3 )
		{
			return ret;
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			// 左边的到正数，没有匹配的了
			if (nums[i] > 0 )
				break;
			// 如果
			if (i > 0 && nums[i] == nums[i-1])
				continue;
			// 右边界限不变，左边依次递增
			int l = i + 1;
			int r = nums.size() - 1;

			while (l<r)
			{
				// 三数之和
				int sum = nums[i] + nums[l] + nums[r];
				if (sum == 0)
				{
					ret.push_back({ nums[i],nums[l],nums[r] });
					// 因为不能有重复项，所以依此跳过
					while (l < r && nums[l] == nums[l + 1])
						l++;
					while (l < r && nums[r] == nums[r - 1])
						r--;
					l++;
					r--;
				}
				// 通过结果来调整界限
				else if (sum > 0)
					r--;
				else if(sum < 0)
					l++;
	
			}

		}

			


		return ret;
    }
};