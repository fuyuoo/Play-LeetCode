// 关键点和另一个题目的不同点就是，不能只是部分子树，要是全部子树。也就是说要到叶子节点
class Solution {
private:
    bool isSame(TreeNode* s, TreeNode* t){
        if(!t && !s) return true;
        if(s && t && s->val == t->val){
            return isSame(s->left,t->left) && isSame(s->right,t->right);
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s || !t) 
            return false;
        if(s->val == t->val && isSame(s,t)){
            return true;
        }else if(isSubtree(s->left,t) || isSubtree(s->right,t)){
            return true;
        }
        return false;
    }
};