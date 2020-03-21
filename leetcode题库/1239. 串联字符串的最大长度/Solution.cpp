// 回溯法，好久没用了，都忘记了
// 其实就是排列组合，看排列之后是否满足
class Solution {
private:
    int res = -1;
    void helper(vector<string>& arr,vector<int>& cache,int curCount,int index){
        for(int& i :cache)
            if(i > 1) return;
        res = max(res,curCount);
        for(int i = index ; i <arr.size(); i++){
            for(char& t :arr[i])
                cache[t-'a']++;
            helper(arr,cache,curCount + arr[i].size(),i+1);
            for(char& t :arr[i])
                cache[t-'a']--;
        }
    }
public:
    int maxLength(vector<string>& arr) {
        vector<int> cache(26);
        helper(arr,cache,0,0);
        return res;
    }
};