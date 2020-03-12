class Solution {
private:
    int res ;
    void binarySearch(TreeNode* root, double target){
        if(!root)
            return ;
        if(abs(root->val - target) < abs(res - target))
            res = root->val;
        if(root->val > target)
            binarySearch(root->left, target);
        else
            binarySearch(root->right, target);
    }
public:
    int closestValue(TreeNode* root, double target) {
        if(!root) return 0;
        res = root->val;
        binarySearch(root, target);
        return res;
    }
};