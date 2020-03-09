class BSTIterator {
private:
    vector<int> record;
    int index;
    void inorder(TreeNode* root){
        if(!root)
            return ;
        inorder(root->left);
        record.emplace_back(root->val);
        inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
        index = 0;
    }
    
    /** @return the next smallest number */
    int next() {
        return record[index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index < record.size();
    }
};