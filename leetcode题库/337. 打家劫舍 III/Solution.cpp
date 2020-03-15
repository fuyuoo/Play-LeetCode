// 选或不选，这是一个问题
// 使用备忘录优化
class Solution {
private:
    unordered_map<TreeNode*,int> cache;
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(cache.find(root) != cache.end()) return cache[root];
        int res1 = root->val;
        // rob
        if(root->left){
            res1 +=(rob(root->left->left) + rob(root->left->right));
        }
        if(root->right)
            res1 += (rob(root->right->left) + rob(root->right->right));
        // dont rob
        int res2 = rob(root->left) + rob(root->right);

        return cache[root] = max(res1,res2);
    }
};