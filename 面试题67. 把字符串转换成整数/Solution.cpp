// 有些繁琐，应该可以更优化一些
class Solution {
public:
    int strToInt(string str) {
        int nag = 1;
        int index = 0;
        str.erase(0, str.find_first_not_of(' '));
        int n = str.size();
        if(n == 0)
            return 0;
        if(str[0] < '0' || str[0] > '9'){
            if(str[0] == '-'){
                nag = -1;
                index = 1;
            }else if(str[0] == '+'){
                index = 1;
            }else
                return 0;
        }
        long ret = 0;
        for(int i = index ; i < str.size() ; i++){
            if(isdigit(str[i])){
                ret = (ret * 10 + str[i] - '0');
                if(ret * nag > INT_MAX)
                    return  INT_MAX;
                else if(ret*nag < INT_MIN)
                    return  INT_MIN;
            }else{
                break;
            }
        }
        return nag * ret;
    }
};