// 双指针，看是否能尝试dur，如果第一个的头比第二个尾大则，第二个往前，反过来也是
// 满足重合区间的时候，重叠时间是否足够
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int n = slots1.size();
        int m = slots2.size();
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            int s1 = slots1[i][0];int e1 = slots1[i][1];

            int s2 = slots2[j][0];int e2 = slots2[j][1];

            if(e1 <= s2)
                i++;
            else if(e2 <= s1)
                j++;
            else if(s1 >= s2){
                int mine = min(e1,e2);
                int dur = mine - s1;
                if(dur >= duration) 
                    return {s1,s1+duration};
                j++;
            }else{
                int mine = min(e1,e2);
                int dur = mine - s2;
                if(dur >= duration) 
                    return {s2,s2+duration};
                i++;
            }
        }
        return {};

    }
};