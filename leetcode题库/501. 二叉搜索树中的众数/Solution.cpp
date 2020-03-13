
 // 其实因为中序是有序的，就和给定有序数组，然后找出众数一样
class Solution {
private:
    vector<int>res;
    void dfs(TreeNode* root,int& maxTime,int& curTime,TreeNode*& pre){
        if(!root)
            return ;
        dfs(root->left,maxTime,curTime,pre);
        if(pre)
            curTime = pre->val == root->val?curTime+1:1;
        if(curTime > maxTime){
            res.clear();
            res.emplace_back(root->val);
            maxTime = curTime;
        }else if (curTime == maxTime)
            res.emplace_back(root->val);
        pre = root;
        dfs(root->right,maxTime,curTime,pre);

    }
public:
    vector<int> findMode(TreeNode* root) {
        if(!root)
            return {};
        TreeNode* pre = nullptr;
        int curTime = 1;
        int maxTime = 0;
        dfs(root,maxTime,curTime,pre);

        return res;
    }
};