class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> maxdata;
        vector<int> res;
        for(int i = 0 ; i < nums.size() ; i++){
            while(!maxdata.empty() && nums[i] > nums[maxdata.back()])
                maxdata.pop_back();
            maxdata.emplace_back(i);
            if(i - maxdata.front() >= k)
                maxdata.pop_front();
            if(i >= k - 1)
                res.emplace_back(nums[maxdata.front()]);

        }
        return res;
    }
};