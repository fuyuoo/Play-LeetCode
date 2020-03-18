// 看起来很难，其实点限制住就可以使他不重叠
// 一个的最左边 和一个的最右边 没有接触
// 或者一个的最上面和一个的最下面 没有接触
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[2] <= rec2[0] || rec1[0] >=rec2[2])
            return false;
        if(rec1[1] >= rec2[3] || rec1[3] <= rec2[1])
            return false;
        return true;
    }
};