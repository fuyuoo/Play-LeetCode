// 不能只使用pivot 是因为，一个是前序的Pivot  一个是中学的pivot
class Solution {
private:
    TreeNode* helper(vector<int>& preorder, int l,int r,vector<int>& inorder,int m,int n){
        if(l > r ) return nullptr;
        int pivot = m;
        int count = 0 ;
        while(inorder[pivot] != preorder[l]){
            pivot++;
            count++;
        }
        TreeNode* node = new TreeNode(preorder[l]);
        node->left = helper(preorder, l+1, count + l , inorder, m, pivot-1);
        node->right = helper(preorder, count + l  + 1, r, inorder, pivot+1, n);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};