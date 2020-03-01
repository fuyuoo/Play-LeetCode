const int maxTime = 100001;
class Solution {
public:
	int maxEvents(vector<vector<int>>& events) {
		if (events.size() == 0) return 0;
        vector<vector<int>> left(maxTime);

		for (int i = 0; i < events.size(); i++) {
			left[events[i][0]].emplace_back(i);
		}
		priority_queue<int, vector<int>, greater<>> pq;
		int count = 0;
		for (int i = 0; i < maxTime; i++) {
			for (int t : left[i]) {
				pq.push(events[t][1]);
			}
			while (!pq.empty() && pq.top() < i) {
				pq.pop();
			}
			if (!pq.empty()) {
				pq.pop();
				count++;
			}

		}
		
		return count;
	}
};