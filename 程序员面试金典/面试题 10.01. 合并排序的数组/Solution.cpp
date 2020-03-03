class Solution {
public:
	void merge(vector<int>& A, int m, vector<int>& B, int n) {
		if (m == 0)
			A = B;
		m--;
		n--;
		for (int i = A.size() - 1; i >= 0 && n >=0; i--) {
			if (n == -1 || (m != -1 && A[m] > B[n])) {
				A[i] = A[m];
				A[m--] = INT_MIN;
			}
			else if (m == -1 || (n != -1 &&A[m] <= B[n])) {
				A[i] = B[n--];
			}
		}

	}
};