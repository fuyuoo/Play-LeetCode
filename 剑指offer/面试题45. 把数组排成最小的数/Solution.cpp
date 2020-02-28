struct mycmp
{
	bool operator () (const string& s1, const string& s2)
	{
		string s3 = s1 + s2;
		string s4 = s2 + s1;
		return s3 > s4;
	}
};
class Solution {
public:
    string minNumber(vector<int>& nums) {
        priority_queue<string, vector<string>, mycmp> q;
        for(int i = 0 ; i < nums.size() ; i++){
            q.push(to_string(nums[i]));
        }
        string ret = "";
        while(!q.empty()){
            ret += q.top();
            q.pop();
        }
        return ret;
    }
};