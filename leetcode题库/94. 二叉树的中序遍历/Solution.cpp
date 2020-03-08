class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        while(!s.empty() || root){
            while(root){
                s.push(root);
                root = root->left;
            }
            if(!s.empty()){
                root = s.top();
				// pop 出来 说明第二次访问到
                s.pop();
                res.emplace_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};