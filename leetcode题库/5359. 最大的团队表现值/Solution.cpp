// 贪心算法，先按效率排序，然后使用优先队列，小顶堆，只存当前最大效率的前k个人，然后每次都用当前speed计算一下
struct Engineer {
    int s;
    int e;
    Engineer(int _s, int _e) : s(_s), e(_e) {}
    bool operator < (const Engineer &r) const {
        return this->e > r.e;
    }
};
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<Engineer> vec;
        for(int i = 0 ; i < n ; i++){
            vec.emplace_back(Engineer(speed[i],efficiency[i]));
        }
        sort(vec.begin(),vec.end());
        priority_queue<int, vector<int>, greater<>> pq;
        long long res = 0;
        long long  speedSum = 0;
        for(int i = 0 ;i < n ; i++){
            speedSum += vec[i].s;
            pq.push(vec[i].s);
            if(pq.size() > k){
                speedSum -= pq.top();
                pq.pop();
            }
            res = max(res,vec[i].e * speedSum);
        }
        return res%(1000000007);
    }
};