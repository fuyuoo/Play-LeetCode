// 切菜题，就是可以看成各个联通分量
class Solution {
private:
    vector<vector<int>> visited ;
    vector<vector<int>> offset = {{-1,-1},{-1,0},{-1,1},{1,0},{1,-1},{1,1},{0,1},{0,-1}};
    int count ;
    void helper(vector<vector<int>>& land,int x,int y){

        int res = 0 ;
        visited[x][y] = true;
        for(int i = 0 ; i < 8; i++){
            int nx = x + offset[i][0];
            int ny = y + offset[i][1];
            if(nx >=0 && nx < land.size() && ny >=0 && ny < land[0].size() && !visited[nx][ny] && land[nx][ny] == 0){
                count ++;
                helper(land, nx, ny);
            }
        }
    }
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        visited = vector<vector<int>>(m,vector<int>(n,false));
        vector<int> res;
        count = 1 ;

        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j++){
                if( !visited[i][j] && land[i][j] == 0){
                    helper(land, i, j);
                    res.emplace_back(count);
                    count = 1 ;

                }
            }
        }
        sort(res.begin(),res.end());
        return res;

    }
};