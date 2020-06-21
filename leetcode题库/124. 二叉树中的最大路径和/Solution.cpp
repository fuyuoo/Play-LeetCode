 // 相当于遍历一颗树，找到最大连续子序列和
 // 使用后序遍历，这样就会先得到左右子树结果然后回到根节点
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