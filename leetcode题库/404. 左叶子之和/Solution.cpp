// 同统计节点数，但是根据上一层判断这一层是否左孩子，然后判断是否是叶子
class Solution {
private:
    int helper(TreeNode* root,bool isLeft){
        if(!root) return 0;
        int res = 0;
        if(isLeft && !root->left && !root->right){
            res = root->val;
        }
        res += helper(root->left,true);
        res += helper(root->right,false);

        return res;
       
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root,false);
    }
};