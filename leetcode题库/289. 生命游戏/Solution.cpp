class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> xoffset = {0,0,1,-1,1,1,-1,-1};
        vector<int> yoffset = {1,-1,0,0,1,-1,1,-1};
        int m = board.size();
        int n = board[0].size();
        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j ++){
                int count = 0;
                for(int k = 0 ; k < 8 ; k++){
                    int nx = i + xoffset[k];
                    int ny = j + yoffset[k];
                    if(nx >=0 && nx < m && ny >=0 && ny < n){
                        count += (board[nx][ny]&1);
                    }
                }
                if((board[i][j]&1) > 0){
                    if(count >= 2 && count <=3){
                        board[i][j] = 0b11;
                    }
                }else if(count == 3)
                    board[i][j] = 0b10;
            }
        }
        for(int i = 0 ; i < m ; i ++)
            for(int j = 0 ; j < n ; j ++)
                board[i][j] >>=1;

    }
};