// 和序列化树差不多，自己写的超时了，原因在于计算层树的时候拷贝了队列，所以一开始先计算好层树，就可以避免拷贝
class Solution {
private:
	TreeNode* helper(queue<int>& q, int level) {
		if (q.empty() || q.front() != level)
			return nullptr;
		q.pop();
		int str = q.front();
		q.pop();
		TreeNode* node = new TreeNode(str);;
		node->left = helper(q, level + 1);
		node->right = helper(q, level + 1);
		return node;



	}
public:
	TreeNode* recoverFromPreorder(string S) {
		queue<int> q;
		string tmp;
		q.push(0);
		for (int i = 0; i < S.size(); ) {
			if (S[i] == '-') {
				q.push(stoi(tmp));
				tmp = "";
				int count = 0;
				while (S[i] == '-') {
					count++;
					i++;
				}
				q.push(count);
			}
			else {
				tmp += S[i];
				i++;
			}
		}
		q.push(stoi(tmp));
		return helper(q, 0);
	}
};