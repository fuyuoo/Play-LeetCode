class Solution {
private:
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* pre = nullptr;
        while(root){
            if(root->val > p->val){
                pre = root;
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return pre;
    }
};