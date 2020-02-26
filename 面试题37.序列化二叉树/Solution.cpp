/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string serString = "";
    void helper1(TreeNode* root){
        if(!root){
            serString +="#!";
            return;
        }
        serString += to_string(root->val) + "!";
        helper1(root->left);
        helper1(root->right);        

    }
    list<string> MySplit(string data){
        string tmp = "";
        list<string> ret;
        for(int i = 0 ; i < data.size() ; i++){
            if(data[i] == '!'){
                ret.emplace_back(tmp);
                tmp = "";
            }else{
                tmp+=data[i];
            }
        }
        return ret;
    }
    TreeNode* helper2(list<string>& q){
        if(q.empty())
            return nullptr;
        string cur = q.front();
        q.pop_front();
        if(cur == "#")
            return nullptr;
        TreeNode* node = new TreeNode(stoi(cur));
        node->left = helper2(q);
        node->right = helper2(q);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        helper1(root);
        return serString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> splits = MySplit(data);

        return helper2(splits);

    }
};
