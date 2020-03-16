// 使用队列可以不需要排序
// 看每次的数是否能加减
class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
		queue<int> q;
		vector<int> res;
		for(int i = 0 ; i <= 9 ; i++)
			q.push(i);
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			if(cur >= low && cur <=high)
				res.emplace_back(cur);
			if(cur == 0 ||cur > high || cur >= 2e8) continue;

			int lastNum = cur % 10;
			if(lastNum >0)
				q.push(cur*10+lastNum - 1);
			if(lastNum < 9)
				q.push(cur*10+lastNum + 1);

		}
		return res;
    }
};