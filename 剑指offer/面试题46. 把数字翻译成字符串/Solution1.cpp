class Solution {
private:
	int tanslate(string& str, int l) {
		if (l >= str.size() -1)	return 1;
		int first = str[l] - '0';
		int second = str[l + 1] - '0';
		int tmpt = first * 10 + second;
		int sum = 0;
		if (tmpt < 26 && tmpt > 9)
			sum += tanslate(str, l + 2);
		sum += tanslate(str, l + 1);
		return sum;

	}
public:
	int translateNum(int num) {
		string str = to_string(num);
		return tanslate(str, 0);
	}
};
