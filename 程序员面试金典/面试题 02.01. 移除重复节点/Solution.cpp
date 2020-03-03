class Solution {
public:
	ListNode* removeDuplicateNodes(ListNode* head) {
		unordered_set<int> set;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		while (head) {
			set.insert(head->val);
			ListNode* next = head->next;
			while (next && set.find(next->val) != set.end()) {
				next = next->next;
			}
			head->next = next;
			head = head->next;
		}
		return dummy->next;
	}
};