// 二叉搜索树的后序遍历，顺序为左右跟
// 只要找到第一个比跟大的元素，那边起就是当前跟的右子树（也就是都比跟大，如果矛盾则不是后序）
// 然后递归寻找左子树和右子树是否满足条件
class Solution {
private:
    bool helper(vector<int>& postorder,int l,int r){
        if(l >= r)
            return true;
        int m = l;
        while(postorder[m] < postorder[r])
            m++;
        for(int i = m ; i <= r ; i++){
            if(postorder[i] < postorder[r])
                return false;
        }
        return helper(postorder,l,m-1) && helper(postorder,m,r-1);

    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() == 0)
            return true;
        return helper(postorder,0,postorder.size() - 1);
    }
};