class Solution {
public:
	int trap(vector<int>& height) {
		stack<int> s;
		int n = height.size();
		int res = 0;
		for (int i = 0; i < n; i++) {
			while (!s.empty() && height[i] > height[s.top()]) {   // 如果当前高度比栈中还大，则说明栈中的可以计算积水了
				int h = height[s.top()];          // 栈中的高度
				s.pop();
				if (s.empty()) break;             // 如果后面没墙了，无法积水
				int w = i - s.top() - 1;          // 当前墙和后面一堵墙
				int minheight = min(height[i], height[s.top()]);  // 短板效应
				res += w * (minheight - h);       // 计算积水
			}
			s.push(i);
		}
		return res;
	}
};