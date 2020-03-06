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
    TreeNode* dfs(vector<int>& nums,int l,int r){
        if(r < l) return nullptr;

        int mid = l + (r - l) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = dfs(nums,l,mid-1);
        node->right = dfs(nums,mid+1,r);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1);
    }
};