// 模拟，碰到墙壁则方向相反，计算具体坐标
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int directX = 1,directY = 1;
        vector<vector<int>> receive = {{p,0},{p,p},{0,p}};
        vector<int> position = {0,0};
        while(true){
            position[0] += directX * p;
            directX = - directX;
            position[1] += directY * q;

            if(position[1] > p){
                position[1] = p - (position[1] - p);
                directY = - directY;
            }else if(position[1] < 0){
                position[1] = -position[1];
                directY = -directY;
            }
            for(int i = 0 ; i < receive.size() ; i++){
                if(receive[i] == position)
                    return i;
            }
        }
        return -1;
    }
};