
// 使用贪心思想
// 先把会议按开始实现排序
// 然后使用按结束时间的最小堆
// 取出堆顶元素，比较是否下一个会议能开始（开始时间小于上个会议的结束时间）
// 如果能直接开始，则改变元素的结束时间（为新会议的结束时间），加入堆
// 如果不能则新开一个房间（加入最小堆）
// 最后看堆中元素个数，就是需要的会议室个数（因为如果满足的就不需要进堆 +0，不满足就需要进 +1，）
struct cmp{
    bool operator()(vector<int>& a,vector<int>& b){
        return a[1] > b[1];
    }
};
bool interCmp(vector<int>& a,vector<int>& b){
    return a[0] < b[0];
}
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
        sort(intervals.begin(),intervals.end(),interCmp);
        pq.push(intervals[0]);

        for(int i = 1 ; i < intervals.size() ; i++){
            vector<int> cur = pq.top();
            pq.pop();
            if(cur[1] <= intervals[i][0]){
                cur[1] = intervals[i][1];
            }else{
                pq.push(intervals[i]);
            }
            pq.push(cur);
                
        }
        return pq.size();
    }
};