// 就按起始时间排序，然后看是否会重叠时间，基础题
bool cmp(vector<int>& a,vector<int>& b){
    return a[0] < b[0];
}
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return true;
		sort(intervals.begin(), intervals.end(), cmp);
        for(int i = 1 ; i < intervals.size(); i++){
            if(intervals[i-1][1] > intervals[i][0])
                return false;
        }
        return true;

    }
};