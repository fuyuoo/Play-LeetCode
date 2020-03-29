// BFS 步步为营
class Solution {
private:
    int xoffset[4] = {0,1,0,-1};
    int yoffset[4] = {1,0,-1,0};
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i = 0 ; i < grid.size() ; i ++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1)
                    q.push({i,j});
            }
        }
        if(q.empty())
            return -1;
        pair<int,int> point;
        bool hasOcean = false;
        while(!q.empty()){
            point = q.front(); 
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nx = point.first + xoffset[i];
                int ny = point.second + yoffset[i];
                if(nx >=0 && nx < grid.size() && ny >=0 && ny < grid[0].size() && grid[nx][ny] == 0){
                    grid[nx][ny] = grid[point.first][point.second] + 1;
                    hasOcean = true;
                    q.push({nx,ny});

                }

            }

        }
        if(!hasOcean)
            return -1;
        return grid[point.first][point.second] - 1;
    }
};