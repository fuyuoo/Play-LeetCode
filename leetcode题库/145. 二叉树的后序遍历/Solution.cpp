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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* lastNode = nullptr;
        vector<int> res;
        stack<TreeNode*> s;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            if(!s.empty()){
                root = s.top();
                s.pop();
                // 如果右边没有元素或者右边是上一个访问的元素，说明这就是后序的遍历，说明是第三次访问到该节点
                if(!root->right || root->right == lastNode){
                    res.emplace_back(root->val);
                    lastNode = root;
                    root = nullptr;
                }else{
                    // 如果右边有，则往右边遍历
                    s.push(root);
                    root = root->right;

                }
            }
        }
        return res;

    }
};