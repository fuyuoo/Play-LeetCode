class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int n = q.size();
        q.push(x);
        for(int i = 0 ; i < n ;  i++){       // 关键，就是每次入队的时候，都把所有的出队再入队下，两级反转
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};