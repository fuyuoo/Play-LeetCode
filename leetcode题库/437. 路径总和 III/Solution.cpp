// 每个节点都开始遍历，因为有负值，所以找到了还可以往下找
class Solution {
private:
    int helper(TreeNode* root,int sum){
        if(!root)
            return 0 ;
        int res = 0;

        if(sum == root->val){
            res ++;
        }
        res += helper(root->left,sum - root->val);
        res += helper(root->right,sum - root->val);
        return res;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        int res = helper(root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);

        return res;
    }
};