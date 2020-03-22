// 就是有k个鸡蛋， 如果尝试丢没有碎，可以再次使用，可以测出多少层，直到达到楼层数，看需要多少次
// 递归终止条件就是，如果还有一个鸡蛋，就还有多少层就要试多少次
// 或者只有一层了，就是一次
class Solution {
private:
public:
    int superEggDrop(int K, int N) {
        int remainTest = 1;
        while(getMaxHeight(remainTest,K) < N)
            remainTest++;
        return remainTest;
    }
    int getMaxHeight(int remainTest,int k){
        if(remainTest == 1 || k == 1)
            return remainTest;
        return getMaxHeight(remainTest -1,k-1) + getMaxHeight(remainTest-1 ,k) + 1;
    }

};