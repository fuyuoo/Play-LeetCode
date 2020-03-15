// 纯暴力
class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		vector<int> res;
		for (int i = 0; i < matrix.size(); ++i)
		{
			int minnum = INT_MAX;
			int minyindex = -1;
			for (int j = 0; j < matrix[0].size(); ++j)
				if(matrix[i][j] < minnum)
				{
					minnum = matrix[i][j];
					minyindex = j;
				}
			bool flag = true;
			for (int j = 0; j < matrix.size(); ++j)
				if(matrix[j][minyindex] > minnum)
				{
					flag = false;
					break;
				}
			if (flag)
				res.emplace_back(minnum);

		}
		return res;
	}
};