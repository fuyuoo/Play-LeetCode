/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int maxSum = INT_MIN;
    int postOrder(TreeNode* root){
        if(!root) return 0;
        int l = max(0,postOrder(root->left));
        int r = max(0,postOrder(root->right));
        maxSum = max(maxSum,l + r + root->val);
        return max(l,r) + root->val;  

    }
public:
    int maxPathSum(TreeNode* root) {
        postOrder(root);
        return maxSum;
    }
};