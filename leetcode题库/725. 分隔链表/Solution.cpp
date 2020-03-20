// 就是先均分，然后再从前面分
// 主要是就是我总想一些骚操作，以后要先把直观的写出来再看
class Solution
{
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k)
	{
		int len = 0;
		ListNode* p = root;
		while (p)
		{
			p = p->next;
			len++;
		}
		int get = len / k;
		int remain = len % k;
		vector<int> split(k, get);
		for (int i = 0; i < remain; i++)
			split[i]++;
		vector<ListNode*> res(k,nullptr);
		for (int i = 0 ;  i <split.size() ;i++)
		{
			ListNode* dummy = new ListNode(-1);
			if (!root) break;
			dummy->next = root;
			while (split[i]-- > 1)
				root = root->next;
			res[i] = dummy->next;
			ListNode* next = root->next;
			root->next = nullptr;
			root = next;
		}
		return res;
	}
};
