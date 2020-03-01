
// 和会议的问题一样，区间问题，先按起始时间排序
// 然后保存前一个的结束时间，如果当前的要开始了，前一个还没结束，则这个放弃，结束时间为两个结束时间的最小值，count++
// 如果前一个已经结束了，则继续
bool cmp(vector<int>& a,vector<int>& b){
    return a[0] < b[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        sort(intervals.begin(),intervals.end(),cmp);

        int preend = intervals[0][1];
        int count = 0;
        for(int i = 1 ; i<intervals.size() ; i++){
            if(intervals[i][0] >= preend){
                preend = intervals[i][1];
            }else{
                preend = min(preend,intervals[i][1]);
                count ++;
            }
        }
        return count;
    }
};