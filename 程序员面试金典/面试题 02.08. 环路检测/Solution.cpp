class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return nullptr;
        ListNode* fast = head;
        ListNode* temp = head;
        while(fast && fast->next){
            fast = fast->next->next;
            head = head->next;
            if(fast == head) break;
        }
        if(temp->next && fast == head){
            head = temp;
            while(fast != head){
                fast = fast->next;
                head = head->next;
            }
            return fast;
        }

        return nullptr;
    }
};