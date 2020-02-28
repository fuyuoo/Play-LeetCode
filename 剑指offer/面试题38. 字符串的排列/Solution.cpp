class Solution {
private:

    void helper(string s,int l,int r){
    
        for(int i = l ; i < r ;i++){
            if(i != l && s[l] != s[i]){
                swap(s[l], s[i]);
            }
        }
    }
public:
    vector<string> permutation(string s) {
        sort(s.begin(),s.end());

        return d;
    }
};