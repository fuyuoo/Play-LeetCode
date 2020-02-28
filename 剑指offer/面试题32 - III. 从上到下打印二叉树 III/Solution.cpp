/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            ret.emplace_back(vector<int>());
            while(n--){
            TreeNode* cur = q.front();
            q.pop();
            // if(level % 2 == 0)
            ret[level].emplace_back(cur->val);
            // else
                // ret[level].insert(ret[level].begin(), cur->val);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            }
            if(level % 2 == 1)
                reverse(ret[level].begin(), ret[level].end());
            level++;

            
        }
        return ret;
        
    }
};