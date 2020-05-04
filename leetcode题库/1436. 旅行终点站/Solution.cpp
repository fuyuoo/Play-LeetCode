// 找到没有出度的点
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> map;
        for(int i = 0 ; i < paths.size() ; i++){
            map[paths[i][0]]++;
        }
        for(int i = 0 ; i < paths.size();i++){
            for(int j = 0 ; j < 2 ;j++){
                if(map[paths[i][j]] == 0)
                    return paths[i][j];
            }
        }
        return "";
    }
};