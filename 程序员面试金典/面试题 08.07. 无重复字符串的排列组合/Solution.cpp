class Solution {
private:
    vector<string> res;
    vector<bool> visited;
    void helper(string& S,string cur){

        if(S.size() == cur.size()){
            res.emplace_back(cur);
            return ;
        }

        for(int i = 0 ; i < S.size() ; i++){
            int n = S[i] ;
            if(!visited[n]){
                visited[n] = true;
                helper(S,cur+S[i]);
                visited[n] = false;
            }
        }

    }
public:
    vector<string> permutation(string S) {
        visited = vector<bool>(256);
        helper(S,"");

        return res;
    }
};