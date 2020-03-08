// 因为蓝灯说明前面都蓝灯
// 依次保存最大到过的灯的id
// 因为保存的是最右边的一个亮的灯的id , 如果点灯次数也等于Id ，说明全部点亮
// 初始化为1 是因为第一个默认蓝灯
class Solution {
public:
	int numTimesAllBlue(vector<int>& light) {
		int n = light.size();
        int cm = 1;
        int count = 0;
		for(int i = 0 ; i < light.size() ;i++){
            cm = max(cm,light[i]);
            if(i + 1 == cm )
                count++;
        }
        return count;
	}
};