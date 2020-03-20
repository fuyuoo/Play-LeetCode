// 思路：固定左边的点，建立一个Map,key为斜率，看以这个点为重心最多多少个
// 3个以下的直接取前两个就行
class Solution {
private:
	double getRate(int x,int y,int x1,int y1)
	{
		int dx = x1 - x;
		int dy = y1 - y;
		if (dx == 0)
			return -3.131;
		return double(dy) / dx;
	}
public:
	vector<int> bestLine(vector<vector<int>>& points) {
		int count = -1;
		vector<int> tmp(0);
        if(points.size() <= 3)
            return {0,1};
		unordered_map<double, vector<int>> map;
		for (int i = 0; i < points.size(); ++i)
		{
			map.clear();
			for (int j = i+1; j < points.size(); ++j)
			{
				double rate = getRate(points[i][0], points[i][1], points[j][0], points[j][1]);
				map[rate].emplace_back(j);
			}
			for (auto iter = map.begin();iter != map.end() ; ++iter)
			{
				int d = iter->second.size();
				if (d > count)
				{
					count = iter->second.size();
					tmp = iter->second;
					tmp.emplace_back(i);
				}
			}
		}

		sort(tmp.begin(), tmp.end());
		return { tmp.front(),tmp[1]};
	}
};