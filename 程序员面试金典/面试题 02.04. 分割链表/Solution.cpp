class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* cur = head;
		ListNode* pre = head;
		while (cur) {
			if (cur->val < x)
			{
				int tmp = cur->val;
				cur->val = pre->val;
				pre->val = tmp;
				pre = pre->next;
			}
			cur = cur->next;
			
		}
		return head;
	}
};