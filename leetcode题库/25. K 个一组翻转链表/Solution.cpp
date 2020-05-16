// 递归实现
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre = head;
        int count = 0;
		// 得到该反转后的头结点
        while(pre && count < k){
            pre = pre ->next;
            count++;
        }
		// 判断当前是否需要反转
        if(count == k){
            pre = reverseKGroup(pre,k);
			// 反转链表操作
            while(count--){
                ListNode* next = head->next;
                head->next = pre;
                pre = head;
                head = next;
            }
            head = pre;
        }
        return head;
    }
};