//dp 使用每一个节点作为根节点，该节点左边和右边又有作为根节点，所以是乘积关系
// 而且这种根有n个，则相加
class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            for(int j = 1 ; j <= i ; j++){
                dp[i] += (dp[j-1] * dp[i - j]);
            }
        }
        return dp[n];
	}

};
这一题动态规划的方法，仔细想一下还是很简单的。对于每一个根i他都是由左边子树（1, 2, ..., i - 1)和右边子树（i + 1, i + 2, ..., n)组成的。因此他的个数肯定是两个子树情况的积。而且，这种根一共有n个，再将这些加起来就可以了。

作者：jerry-peng
链接：https://leetcode-cn.com/problems/unique-binary-search-trees/solution/xi-xiang-yi-xia-huan-shi-hen-jian-dan-de-by-jerry-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。