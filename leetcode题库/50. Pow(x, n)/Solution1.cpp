// 递归法，备忘录优化
class Solution {
private:
    unordered_map<long,double> map;
    double _myPow(double x, long n) {
        if(map.find(n) != map.end())
            return map[n];
        if(n > 0 ){
            if(n == 1)
                return x;
            if(n%2 == 0){
                map[n] =  _myPow(x,n/2) * _myPow(x,n/2);
            }else{
                map[n] =  _myPow(x,n/2) * _myPow(x,n/2+1);
            }
            return map[n];
        }else if( n == 0){
            return 1;
        }else{
            return 1/_myPow(x,-n);
        }
    }
public:
    double myPow(double x, int n) {
        return _myPow(x,n); 
    }
};