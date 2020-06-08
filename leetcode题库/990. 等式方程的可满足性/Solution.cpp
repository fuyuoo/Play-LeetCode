 // 并查集
class unionFind{
    vector<int> data;
public:
    unionFind(){
        data  = vector<int>(26);
        for(int i = 0 ; i < data.size() ; i++)
            data[i] = i;
    }
    int find(int t){
        while(t != data[t])
            t = data[t];
        return t;
    }
    void unionele(int a,int b){
        int aroot = find(a);
        int broot = find(b);
        if(aroot == broot) return;
        data[aroot] = broot;
    }
    bool isConnected(int a,int b){
        return find(a) == find(b);
    }
    
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {

        unionFind equalFind;
        vector<pair<int,int>> list;
        for(string str : equations){
            int a = str[0] - 'a';
            int b = str[3] - 'a';
            if(str[1] == '!'){
                list.push_back({a,b});
            }else{
                equalFind.unionele(a,b);
            }
        }
        for(auto t : list){
            if(equalFind.isConnected(t.first,t.second))
                return false;
        }
        return true;
    }
};
