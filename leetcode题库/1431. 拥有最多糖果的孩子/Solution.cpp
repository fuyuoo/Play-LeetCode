class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

		vector<bool> res(candies.size(),false);
		int maxcandies = 0;
		for (int i : candies) {
			maxcandies = max(maxcandies, i);
		}
		maxcandies -= extraCandies;
		for (int i = 0; i < candies.size(); i++) {
			if (candies[i] >= maxcandies)
				res[i] = true;
		}
		return res;
	}
};