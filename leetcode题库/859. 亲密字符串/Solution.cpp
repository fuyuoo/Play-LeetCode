// 一开始想用字符统计去做，但是发现如果两个单词相同，且没有相同字母则不行,需要加个判断，如果相同单词，则至少一个词频大于1  时间O(n) 空间O(1)
//  后面在官方题解看到一更好的，虽然时间是O(n),空间O（1）,但是很多时候不需要遍历完，因为没有统计所有字母
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if( A.size() != B.size())
            return false;
        if(A == B){
            vector<int> countA(26);
            for(char t:A){
                countA[t - 'a']++;
            }
            for(int t:countA){
                if(t > 1 )
                    return true;
            }
            return false;
        }else{
            int first = -1,secoud = -1;
            for(int i = 0 ; i < A.size() ; i++){
                if(A[i] != B[i]){
                    if(first == -1)
                        first = i;
                    else if(secoud == -1)
                        secoud = i;
                    else
                        return false;;
                }
            }
            return secoud != -1 && A[first] == B[secoud] && A[secoud] == B[first] ;
        }
    }
};