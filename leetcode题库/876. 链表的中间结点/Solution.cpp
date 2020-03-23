// 快慢指针
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* p = head;
        while(p && p->next){
            p = p->next->next;
            head = head->next;
        }
        return head;
    }
};