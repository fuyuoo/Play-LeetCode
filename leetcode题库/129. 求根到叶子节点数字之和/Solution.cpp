class Solution {
private:
    int res ;
    void postOrder(TreeNode* root,int cur){
        if(!root)
            return ;
        cur = cur*10 + root->val;
        if(!root->left && !root->right){
            res += cur;
            return ;
        }
        postOrder(root->left,cur );
        postOrder(root->right, cur);

    }
public:
    int sumNumbers(TreeNode* root) {
        res = 0;
        postOrder(root, 0);
        return res;
    }
};