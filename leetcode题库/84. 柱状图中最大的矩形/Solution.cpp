// 使用栈实现，依次遍历，如果碰到比堆顶高度还小的开始启动（面积到达了极限）
// 一直找，直到栈为空或者找到比当前元素小（不构成矩形，面积矩形的右边界），因为栈中后面的元素肯定比前面小，所以堆顶的到达极限，后面的也可能到达极限
// 以堆顶的元素为heigh ，到堆顶元素下标位置（因为是递增的，所以碰到的第一个肯定是比当前小的，就是面积矩形左边界）
// 有点乱，明天再写过一次
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