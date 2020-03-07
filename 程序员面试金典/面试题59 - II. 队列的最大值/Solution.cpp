// 和队列的最大值另外个题目一样，只是这个变成了个数据结构
class MaxQueue {
private:
    queue<int> q;
    deque<int> maxq;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(maxq.empty()) return -1;
        return maxq.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while(!maxq.empty() && value > maxq.back())
            maxq.pop_back();
        maxq.emplace_back(value);
    }
    
    int pop_front() {
        if(q.empty()) return -1;
        int val = q.front();
        if(val == maxq.front())
            maxq.pop_front();
        q.pop();
        return val;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */