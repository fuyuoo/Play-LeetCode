class Solution {
public:
	// 因为是二叉搜索树，根节点比左大 比右小
	bool verifyPreorder(vector<int>& preorder) {
		int min = INT_MIN;
        stack<int> s;
        for(int t : preorder){
            if(t < min) return false;
            while(!s.empty() && t > s.top()){
                min = s.top();
                s.pop();
            }
            s.push(t);
        }
        return true;
	}
};