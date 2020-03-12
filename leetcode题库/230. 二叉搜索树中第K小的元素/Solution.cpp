class Solution {
private:
    vector<int> cache;
    void helper(TreeNode* root){
        if(!root)
            return ;
        helper(root->left);
        cache.emplace_back(root->val);
        helper(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        cache.clear();
        helper(root);
        return cache[k-1];
    }
};