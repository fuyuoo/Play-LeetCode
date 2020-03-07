// 一开始用的冒泡写的，效率是这个的开方
// O（n） 一开始统计需要用到的0 ，然后一些肯定是0的地方就被舍去了
// 然后需要主要是否加的最后一个是0  是0 则这个不能复写
// 否则从后开始复写
class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		int zeroCount = 0;
		int i = 0;
		int len = arr.size();
		while (i + zeroCount < len) {
			if (arr[i++] == 0)
				zeroCount++;
		}i--;
		int j = len - 1;
		if (zeroCount + i + 1 > len) {
			arr[j--] = arr[i--];
			zeroCount--;
		}
		while (zeroCount > 0) {
			arr[j--] = arr[i];
			if (arr[i] == 0) {
				arr[j--] = arr[i];
				zeroCount--;
			}
			i--;
		}
	}
};