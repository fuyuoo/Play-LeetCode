class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int,int> map;
        int n = mat.size();
        for(int i = 0 ; i <mat[0].size() ; i++){
            for(int j = 0 ; j < mat.size() ; j++){
                map[mat[j][i]]++;
                if(map[mat[j][i]] == n)
                    return mat[j][i];
            }
        }
        return -1;
    }
};