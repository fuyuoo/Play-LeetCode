class Solution {
public:
	int myAtoi(string str) {
		int c = str.find_first_not_of(" ");
        if (c == -1)
			return 0;
		int na = 1;
		long long ret = 0;
		if (str[c] == '-')
		{
			na = -1;
			c += 1;
		}
		else if (str[c] == '+')
		{
			na = 1;
			c += 1;
		}
		for (int i = c; i < str.size(); ++i)
		{
			
			if (!isdigit(str[i]))
				break;
            ret = ret * 10 + str[i] - '0';
            if (ret > INT_MAX || ret < INT_MIN)
                return na == 1?INT_MAX : INT_MIN;
		}
		return ret * na;
	}
};