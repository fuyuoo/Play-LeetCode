// 双路快排
class Solution {
private:
    int partition(vector<int>& nums,int l,int r){
        int t = rand()%(r - l+1) + l;
        int target = nums[t];
        swap(nums[t],nums[l]);
        while(l < r){
            while(l < r && nums[r] >= target)
                r--;
            nums[l] = nums[r];
            while(l < r && nums[l] < target)
                l++;
            nums[r] = nums[l];
        }
        nums[l] = target;
        return l;
    }
    void QuickSort(vector<int>& nums,int l,int r){
        if(l >= r) return ;
        int p = partition(nums,l,r);
        QuickSort(nums,l,p-1);
        QuickSort(nums,p+1,r);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums,0,nums.size()-1);
        return nums;
    }
};