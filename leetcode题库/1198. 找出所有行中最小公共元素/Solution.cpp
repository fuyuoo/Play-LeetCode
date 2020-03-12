class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int sum = 5000;
        for(int i = 0 ; i < arr.size() ; i++){
            sum -= arr[i];
            if(sum < 0)
                return i;
        }
        return arr.size();
    }
};