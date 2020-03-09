class Solution {
private:
    int ans ;
    void dfs(TreeNode* node ,bool preleft,int dis){
        if(!node)
            return ;
        ans = max(ans,dis);
        if(preleft){
            dfs(node->right,!preleft,dis+1);
            dfs(node->left,preleft,1);
        }else{
            dfs(node->left,!preleft,dis+1);
            dfs(node->right,preleft,1);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        ans = 0;
        dfs(root->left, true,1);
        dfs(root->right, false,1);
        return ans;
    }