// 回溯问题
class Solution {
private:
	int count;
	void dfs(vector<int>& rating, int index, int prerate, int curhasPeople) {

		if (curhasPeople == 3) {
			count++;
			return;
		}

		for (int i = index; i < rating.size(); i++) {
			if (rating[i] > prerate) {
				dfs(rating, i + 1, rating[i], curhasPeople + 1);
			}
		}
	}
	void revedfs(vector<int> & rating, int index, int prerate, int curhasPeople) {

		if (curhasPeople == 3) {
			count++;
			return;
		}

		for (int i = index; i < rating.size(); i++) {
			if (rating[i] < prerate) {
				revedfs(rating, i + 1, rating[i], curhasPeople + 1);
			}
		}
	}
public:
	int numTeams(vector<int>& rating) {
		count = 0;
		dfs(rating, 0, INT_MIN, 0);
		revedfs(rating, 0, INT_MAX, 0);
		return  count;
	}
};