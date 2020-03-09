class Solution {
public:
    string sortString(string s) {
        vector<int> countA(26);
        int n = s.size();
        for(char t:s){
            countA[t - 'a']++;
        }
        string res;
        while(n > 0){
            for(int i = 0 ; i < countA.size() ; i++){
                if(countA[i] > 0){
                    res+= (i + 'a');
                    countA[i]--;
                    n--;
                    }
            }
            for(int i = countA.size() -1 ; i >=0 ; i--){
                if(countA[i] > 0){
                    res+= (i + 'a');
                    countA[i]--;
                    n--;
                    }
            }
       }
        return res;
        
    }
};