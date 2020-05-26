// 方法1是使用哈希表，虽然时间复杂度达到了，但是空间复杂度为On。
// 方法2 使用判断环检测的方法，因为在该数组中数是小于数组长度的,所以可以 index = nums[index]的方式进行前进，也就变成了坐标指向数据的链表，这样找到环的开始点就找到了重复数
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0 ;
        int fast = 0;
        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(slow == fast){
                slow = 0;
                while(slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
    }
};