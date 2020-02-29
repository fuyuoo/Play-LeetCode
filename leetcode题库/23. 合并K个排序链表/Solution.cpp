/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 使用优先队列，自定义比较函数创建小顶堆，然后每次取出堆顶元素
 struct mycmp{
     bool operator()(ListNode* node1,ListNode* node2){
         return node1->val > node2->val;
     }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*,vector<ListNode*>,mycmp> pq;
        for(auto t:lists){
            if(t)
                pq.push(t);
        }
        ListNode* head = new ListNode(-1);
        ListNode* ret = head ;
        while(!pq.empty()){
            ListNode* cur = pq.top();
            head->next = cur;
            pq.pop();
            if(cur->next)
                pq.push(cur->next);
            head = head->next;
        }
        return ret->next;

    }
};