/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 这题本来很轻松可以做出来的，昨天做了很多这种类似的题目，但是不是很熟，耽误时间了
class Solution {
private:
    bool helper(ListNode* head, TreeNode* root){
        if(!head)
            return true;
        if(!root)
            return false;
        if(root->val != head->val)
            return false;
        return helper(head->next,root->left) || helper(head->next , root->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head)
            return true;
        if(!root)
            return false;
        return helper(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
        
    }

};