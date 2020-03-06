class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> tmp;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                tmp.emplace_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            res.emplace_back(tmp);
            
        }
        reverse(res.begin(), res.end());
        return res;
    }
};