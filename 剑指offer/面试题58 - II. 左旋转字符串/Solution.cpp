class Solution {
public:
    string reverseLeftWords(string s, int n) {
        n %=s.size();
        string d = s.substr(0, n);
        d = s.substr(n, s.size()-1) + d;
        return d;

    }
};