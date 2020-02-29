// 使用最小堆和最大堆，处理数据流问题
// 再使用一个count 计数，同时用来方便入堆
// 当个数为偶数进入最大堆，但是如果当前加入的元素比最小堆的对顶还大，则和最小堆顶元素交换（元素进入最小堆，最小堆堆顶元素进入最大堆）
// 个数为偶数就是相反的
class MedianFinder {
private:
    priority_queue<int,vector<int>,greater<>> minHeap;
    priority_queue<int, vector<int>, less<>> maxHeap;
    int count;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        if(count % 2 == 0){
            if(!minHeap.empty() && num > minHeap.top()){
                minHeap.push(num);
                num = minHeap.top();
                minHeap.pop();
            }
            maxHeap.push(num);

        }else{
            if(!maxHeap.empty() && num < maxHeap.top()){
                maxHeap.push(num);
                num = maxHeap.top();
                maxHeap.pop();
            }
            minHeap.push(num);
        }
        count ++;
    }
    
    double findMedian() {
        if(count == 0 )
            return 0;
        if(count % 2 == 0){
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }else{
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */