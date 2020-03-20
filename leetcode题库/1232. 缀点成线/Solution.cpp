// 斜率公式  b1 - b2 / a1 - a2
class Solution {
private:
    double getRate(int a,int b,int a1,int b1){
        return double(b1 - b) / (a1 - a);
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        if(coordinates.size() <= 2) return true;
        double rate = getRate(coordinates[0][0],coordinates[0][1],coordinates[1][0],coordinates[1][1]);
        for(int i = 1 ; i < coordinates.size()-1 ; i++){
            double tmprate = getRate(coordinates[i][0],coordinates[i][1],coordinates[i+1][0],coordinates[i+1][1]);
            if(abs(tmprate - rate) > 0.00001)
                return false;
        }
        return true;
    }
};