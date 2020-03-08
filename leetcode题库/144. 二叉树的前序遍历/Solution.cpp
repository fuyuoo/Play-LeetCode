class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        while(!s.empty() || root){
            while(root){
				// 第一次访问到
                res.emplace_back(root->val);
                s.push(root);
                root = root->left;
            }
            if(!s.empty()){
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
        return res;
    }
};