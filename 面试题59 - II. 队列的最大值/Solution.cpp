// 跟滑动窗口的最大值类似
// 关键是pop_front的时候，要判断当前值是不是这组数里的最大值，如果是则会改变队列里的最大值
class MaxQueue {
private:
    list<int> q;
    list<int> maxq;
public:
    MaxQueue() {

    }
    
    int max_value() {
        int ret = -1;
        if(maxq.size() > 0){
            ret = maxq.front();
        }
        return ret;
    }
    
    void push_back(int value) {
        q.emplace_back(value);
        while(!maxq.empty() && value > maxq.back())
            maxq.pop_back();
        maxq.emplace_back(value);
    }
    
    int pop_front() {
        int ret = -1;
        if(q.size() > 0){
            ret = q.front();
            q.pop_front();
            if(maxq.front() == ret) maxq.pop_front();
        }
        return ret;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */