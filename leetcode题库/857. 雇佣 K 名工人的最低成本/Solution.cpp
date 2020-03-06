// 题目意思，因为是雇佣K个最低成本，没说要求质量，而且工资是按照工作质量比例
// 所以尽可能小的工作质量，薪劳比也尽量高，这样就会最少的工资
// 因为要满足所有人的工资，也就是薪劳比要满足，则要满足最大的就可以
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double,int>> workers;   // 按薪劳比排序，优先低的，因为要计算要满足所有人最低工资
        for(int i = 0 ; i < quality.size() ; i++){
            workers.emplace_back(double(wage[i]) / quality[i],quality[i]);
        }
        sort(workers.begin(), workers.end(),  [](pair<double,int>a, pair<double,int>b){ return a.first < b.first; });
        priority_queue<int , vector<int>> pq;   // 最大堆保存前K个最小quality的值，如果使用当前工人，则必须是当前的劳薪比（先排好序了，这个是当前最大的，满足其他工人条件）
		 
        double res = DBL_MAX;
        int curqua = 0;
        for(auto worker : workers){
            curqua += worker.second;
            pq.push(worker.second);
            if(pq.size() == K){
                res = min(res,curqua * worker.first);
                curqua-= pq.top();
                pq.pop();
            }
        }
        return res;
    }
};