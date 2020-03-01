
bool cmp(vector<int>& a,vector<int>& b){
    return a[0] < b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);  // 按起始时间排序
        if(intervals.size() == 0)
            return res;
        vector<int> pre = intervals[0] ;

        for(int i = 1 ; i < intervals.size() ; i++){
            vector<int> cur = intervals[i];
            if( pre[1] < cur[0]){						// 如果后一个区间在前一个结束之后，则继续
                res.emplace_back(pre);
                pre = cur;
            }else if(pre[1] >= cur[0]){					// 否则，则合并区间，结束段为两者的最大值
                pre[1] = max(cur[1],pre[1]);
            }

        }
        res.emplace_back(pre);							// 因为少循环一次，要加回来
        return res;
    }
};