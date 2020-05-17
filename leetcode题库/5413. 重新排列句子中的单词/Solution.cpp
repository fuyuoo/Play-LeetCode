// 使用stringstream流和匿名函数，之前了解过但是没有具体的使用
class Solution
{
public:
	string arrangeWords(string text)
	{
		if (text.empty())
		{
			return text;
		}
        text[0] = std::tolower(text[0]);
		stringstream ss(text);
		string tmp;
		vector<string> data;
		while (ss >> tmp)
		{
			data.emplace_back(tmp);
		}
		stable_sort(data.begin(), data.end(), [](const string& a, const string& b) {
			return a.size() < b.size();
			});

		string res;
		for (int i = 0; i < data.size(); i++)
			res += data[i] + " ";
		res.erase(res.end() - 1);
		res[0] = std::toupper(res[0]);
		return res;
	}
};