// 哈希碰撞的线性探测法，路径压缩
class Solution {
private:
	vector<int> pos;
	int find(int n)
	{
        int t = pos[n];
		if (t == -1)
		{
			pos[n] = n;
			return n;
		}else
		{
			t = find(t + 1);
			pos[n] = t;
			return t;
		}
		
		
	}
public:
	int minIncrementForUnique(vector<int>& A) {
		pos = vector<int>(80000, -1);
		int res = 0;
		for (int i = 0; i < A.size(); ++i)
		{
			int p = find(A[i]);
			res += (p - A[i]);
		}
		return res;

	}
};