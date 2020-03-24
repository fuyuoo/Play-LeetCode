// 其实算法比较简单，主要是建模的过程


class Solution {
private:
	vector<int> f;
	int find(int n) {
		if (n != f[n])
			f[n] = find(f[n]);
		return f[n];
	}
public:
	int minSwapsCouples(vector<int>& row) {
		f = vector<int>(row.size());
		// 先把两对两对的座位合并，构成小环
		for (int i = 0; i < row.size() ; i+=2){
			f[i] = i;
            f[i+1] = i;
        }
		// 然后在把两对两对的人合并，融合成大环

		for (int i = 0; i < row.size() ; i+=2) {
			int a = find(row[i]);
			int b = find(row[i + 1]);
			if (a != b)
				f[a] = b;
		}
		int res = row.size() / 2;// 多少对情侣
		// 看有多少个环
		for (int i = 0; i < row.size(); i++) {
			if (f[i] == i)  // 减去环
				res--;
		}
		return res;
	}
};