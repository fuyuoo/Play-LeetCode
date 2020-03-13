// 编程厉害的往往不是编程厉害的
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<>> pq;
        for(int t : blocks)
            pq.push(t);
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(b + split);
        }
        return pq.top();
    }
};