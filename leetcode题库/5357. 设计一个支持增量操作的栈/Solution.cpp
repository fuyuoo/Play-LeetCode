// 可以使用数组实现栈，这样增量就加到具体数字上去了
// 这种方法是用一个数组记录增量，每次Pop前 才会加上
class CustomStack {
private:
    stack<int> s;
    int capacity;
    vector<int> inc;
public:
    CustomStack(int maxSize) {
        capacity = maxSize;
        inc = vector<int>(maxSize);
    }
    
    void push(int x) {
        if(s.size() < capacity)
            s.push(x);
    }
    
    int pop() {
        if(s.empty())
            return -1;
        int n = s.size();
        int res = s.top() + (inc[n-1]);
        inc[n-1] = 0;
        s.pop();
        return res;
    }
    
    void increment(int k, int val) {
		if (!s.empty())
		{
			int size = s.size();
			int n = min(size, k);
			for (int i = 0; i < n; i++) {
				inc[i] += val;
			}
		}

	}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */