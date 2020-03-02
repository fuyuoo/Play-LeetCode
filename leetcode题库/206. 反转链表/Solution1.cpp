// 递归写法 看懂需要在纸上画一下
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* cur = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return cur;
    }
};