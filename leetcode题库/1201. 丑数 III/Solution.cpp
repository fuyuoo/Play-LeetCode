// 很牛，核心就是例如知道一个数，想看一个范围内能够被这个数整除的数有多少个
// 就是直接用这个除以它，想找到具体是哪一个，再用取余把多余的找出来
// 还有关键就是去掉重叠的
class Solution {
	using LL = long long;
private:
	int binarySearch(int low,LL high , int n, int a, int b, int c) {

		LL mab = MCM(a, b);
		LL mac = MCM(a, c);
		LL mbc = MCM(b,c);
		LL mabc = MCM(a, mbc);
		while (low <= high) {
			LL mid = low + (high - low) / 2;
			LL count = mid / a + mid / b + mid / c - mid / mab - mid / mac - mid / mbc + mid / mabc;
			if (count == n)
				return mid;
			else if (n > count)
				low = mid + 1;
			else
				high = mid - 1;
		}
		return -1;
	}
	LL MCM(LL a, LL b) {

		LL Multi = a * b;

		while (b > 0) {
			LL tmp = a % b;
			a = b;
			b = tmp;
		}

		return Multi / a;
	}

public:
	int nthUglyNumber(int n, int a, int b, int c) {
		int low = min(a, min(b, c));
		LL high = n * low;
		int target = binarySearch(low,high, n, a, b, c);
		a = target % a;
		b = target % b;
		c = target % c;
		return target - min(a,min(b,c));

	}
};