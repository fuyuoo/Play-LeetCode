// 哈希表作用是存储端点的连续长度
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        int res = 0;
        for(int num : nums){
			// 如果当前端点没有数据则进入
            if(map.find(num) == map.end()){
				// 相邻的端点长度
                int left = map.find(num-1) == map.end()?0:map[num-1];
                int right = map.find(num+1) == map.end()?0:map[num+1];
				// 总共长度
                int length = left + right + 1;
                if(length > res)
                    res = length;
				// 把值附上，三个端点的值都一样
                map[num] = length;
                map[num-left] = length;
                map[num+right] = length;

            }

        }
        return res;
    }
};