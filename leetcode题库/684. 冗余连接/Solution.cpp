// 并查集 按顺序判断 当前是否构成了环
// 就是两个节点的根节点是否一样
class Solution {
private:
    vector<int> f;
    int find(int n){
        if(n != f[n])
            f[n] = find(f[n]);
        return f[n];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 0 ; i < edges.size() ; i++)
            f.emplace_back(i);
        for(int i = 0 ; i < edges.size() ; i++){
            int a = find(edges[i][0]-1);
            int b = find(edges[i][1]-1);
            if(a == b)
                return edges[i];
            else{
                f[b] = a;
            }
        }
        return {};
    }
};