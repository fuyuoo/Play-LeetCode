// 转换求解思路，不是从里面求解是否能到两边，而是从边界开始dfs，看有那些点会被两边的边界都访问到
class Solution {
private:
    vector<int> xoffset = {1,0,-1,0};
    vector<int> yoffset = {0,1,0,-1};

    void dfs(vector<vector<int>>& matrix , vector<vector<bool>>& area,int x,int y){

        area[x][y] = true;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + xoffset[i];
            int ny = y + yoffset[i];
            if(nx >= 0 && nx < matrix.size() && ny >=0 && ny < matrix[0].size() && !area[nx][ny]&&  matrix[nx][ny] >= matrix[x][y] ){
                dfs(matrix,area,nx,ny);
            }
        }
        
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        int m = matrix.size();
        if(m == 0) return res;
        int n = matrix[0].size();
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));  // 太平洋
        vector<vector<bool>> pacific(m,vector<bool>(n,false));   // 大西洋
        for(int i = 0 ; i < m ; i++){
            dfs(matrix,atlantic,i,0);
            dfs(matrix,pacific,i,n-1);
        }
        for(int i = 0 ; i < n ; i++){
            dfs(matrix,atlantic,0,i);
            dfs(matrix,pacific,m-1,i);
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(atlantic[i][j]  && pacific[i][j])
                    res.emplace_back(vector<int>({i,j}));

            }
        }
        return res;

    }
};