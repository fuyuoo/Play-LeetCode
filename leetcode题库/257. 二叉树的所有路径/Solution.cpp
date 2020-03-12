class Solution {
private:
    vector<string> res;
    void dfs(TreeNode* root,string cur){
        if(!root)
            return ;
        if(!root->left && !root->right){
            res.emplace_back(cur + to_string(root->val));
            return;            
        }
        dfs(root->left,cur+ to_string(root->val) + "->" );
        dfs(root->right,cur  + to_string(root->val) +  "->");
        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear();
        dfs(root, "");
        return res;
    }
};