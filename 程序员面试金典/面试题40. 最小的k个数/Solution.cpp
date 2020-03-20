class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        for(int t : arr){
            pq.push(t);
        }
        vector<int> res;
        while(k -- )
            res.emplace_back(pq.top()),pq.pop();
        return res;
    }
};