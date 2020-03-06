class Solution {
private:
    int gcd(int x,int y){
        return x == 0 ? y:gcd(y%x,x);
    }
public:
    int mirrorReflection(int p, int q) {
        int k = p * q /gcd(p,q);  // 最小公倍数等于两数成绩除以最大公约数
        int t1 = k / p;         
        int t2 = k / q;
        if(t1 % 2 == 0)
            return 0;
        if(t2 % 2 == 0)
            return 2;
        return 1;

    }
};