class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int res = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(queryTime >= startTime[i] && endTime[i] >= queryTime)
                res++;
        }
        return res;
    }
};