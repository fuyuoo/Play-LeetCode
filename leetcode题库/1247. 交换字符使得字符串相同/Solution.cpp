// 统计 xy yx 的次数  这样的就是要交换的次数
// 然后看他们能否匹配完，如果能匹配完，则取他们的一半，因为重复计算了
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0;
        int yx = 0;
        for(int i = 0 ; i <s1.size() ;i++){
            if(s1[i] == s2[i]) continue;
            else if(s1[i] == 'x')
                xy++;
            else
                yx++;
        }
        return (xy + yx) % 2 == 1?-1:((xy+1)/2+(yx+1)/2);
    }
};