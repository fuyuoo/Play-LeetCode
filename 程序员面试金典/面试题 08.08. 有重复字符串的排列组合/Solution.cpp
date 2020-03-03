class Solution {
private:
    unordered_set<string> res;
    vector<bool> visited;
    void helper(string& S,string cur){

        if(S.size() == cur.size()){
            res.insert(cur);
            return ;
        }

        for(int i = 0 ; i < S.size() ; i++){
            if(!visited[i]){
                visited[i] = true;
                helper(S,cur+S[i]);
                visited[i] = false;
            }
        }

    }
public:
    vector<string> permutation(string S) {
        visited = vector<bool>(S.size());
        helper(S,"");
        vector<string> ts;
        for(string t:res){
            ts.emplace_back(t);
        }
        return ts;
    }
};