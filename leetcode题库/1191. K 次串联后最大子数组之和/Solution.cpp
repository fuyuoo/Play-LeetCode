// 通过不同的情况分类
// 第一种情况，全是正数，全部相加
// 第二种情况，数组和为负数，则区单个数组的连续最大合或者两个数组的连续最大合
// 第三种情况,数组和为正数，如果第一个数组连续最大和和两个一样，则和全部相加比较
// 第四种情况，中间的求和，加上原本连起来的最大连续和，和全部相加比较
class Solution
{
private:
	int getMaxsequenceSum(vector<int>& arr)
	{
		int res = INT_MIN;
		int tmpsum = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			tmpsum += arr[i];
			if (tmpsum < 0)
				tmpsum = 0;
			res = max(res, tmpsum);
		}
		return res;
	}

public:
	int kConcatenationMaxSum(vector<int>& arr, int k)
	{
		vector<int> record(arr.size() * 2);
		long long singlesum = 0;
		long long mod = 1e+9 + 7;
		for (int i = 0; i < arr.size(); i++)
		{
			singlesum += arr[i];
			record[i] = arr[i];
			record[i + arr.size()] = arr[i];
		}
		long long maxsingle = getMaxsequenceSum(arr);
		long long maxTwice = getMaxsequenceSum(record);
		if (k == 1)
		{
			return maxsingle;
		}
		if (singlesum < 0)
			return maxTwice;
		else
		{
			if (maxsingle == maxTwice)
				return max((singlesum * k) % mod, maxsingle);
			else
				return max((singlesum * k) % mod, (maxTwice + (k - 2) * singlesum) % mod);
		}
	}
};