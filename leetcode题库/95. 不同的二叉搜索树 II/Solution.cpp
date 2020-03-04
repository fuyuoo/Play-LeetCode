// 其实和前一题递归类似，只是组合了出来
// 还是没有理解很透 大致是懂了
class Solution {
private:
    vector<TreeNode*> getNodes(int l,int r){
        vector<TreeNode*> res;
        if( l > r){
            res.emplace_back(nullptr);
            return res;
        }
        if( l == r){
            res.emplace_back(new TreeNode(l));
            return res;
        }
        for(int i = l ; i <=r ; i++){
            vector<TreeNode*> leftnode = getNodes(l,i-1);
            vector<TreeNode*> rightnode = getNodes(i+1,r);

            for(TreeNode* left:leftnode){
                for(TreeNode* right : rightnode){
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    res.emplace_back(node);
                }
            }

        }
        return res;

    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return getNodes(1, n);
    }
};