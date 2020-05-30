// 使用栈实现，依次遍历，如果碰到比堆顶高度还小的开始启动（面积到达了极限）
// 栈中只储存比栈顶元素大的元素，所以一遇到比该点小的，则前面一个的最大面积就可以计算了（使用while是因为可能下一个比第二个栈顶还小，再次判断）
// 这样的话计算不到最后一个的元素，所以需要特殊办法加上
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0 ;
        stack<int> s ;
        int n = heights.size();
        for(int i = 0 ; i <= n ; i++){
            while( !s.empty() && (i == n ||heights[i] < heights[s.top()])){
                int height = heights[s.top()];
                s.pop();
                int width = !s.empty() ? i - 1 - s.top():i;    // 这里是计算前一个的面积,所以循环要多一次，或者底下再写一遍
                res = max(res,height * width);

            }
            s.push(i);	                                       // 总是要把当前高度放进栈中
        }
        return res;
    }
};