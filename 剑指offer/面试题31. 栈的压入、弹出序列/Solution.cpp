class Solution
{
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
	{
        if(pushed.size() == 0)
            return true;
		stack<int> s;
        int index = 0;
		for(int i = 0 ; i < pushed.size() ; i++){
            s.push(pushed[i]);
            while(!s.empty() && s.top() == popped[index]){
                s.pop();
                index++;

            }
        }
        return s.empty();
		
	}
};