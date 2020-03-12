/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 前序遍历
class Codec {
public:
    string rootString;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        rootString = "";
        helper1(root);
        return rootString;
    }
    void helper1(TreeNode* root){
        if(!root){
            rootString += "#!";
            return ;
        }
        rootString += to_string(root->val) + "!";
        helper1(root->left);
        helper1(root->right);
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q = split(data);
        return helper2(q);
    }
    TreeNode* helper2(queue<string>& q){
        if(q.empty())
            return nullptr;
        string cur = q.front();
        q.pop();
        if(cur == "#")
            return nullptr;
        TreeNode* node = new TreeNode(stoi(cur));
        node->left = helper2(q);
        node->right = helper2(q);
        return node;
    }
    queue<string> split(string data){
        string cur = "";
        queue<string> res;
        for(int i = 0 ; i < data.size() ; i++){
            if(data[i] == '!'){
                res.push(cur);
                cur = "";
            }else{
                cur += data[i];
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));