// 统计所有的，然后再找
class Solution {
private:
    unordered_map<int,int> map;
    int maxCount;
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int val = left + right + root->val;
        map[val] ++;
        if(map[val] > maxCount){
            maxCount = map[val];
        }
        return val;

    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map.clear();
        dfs(root);
        vector<int> d;
        for(auto t : map){
            if(t.second == maxCount)
                d.emplace_back(t.first);
        }
        return d;
    }
};