// 染色的二分解法
class Solution {
private:
    vector<int> color;
    bool dfs(vector<vector<int>>& graph,int v){
        for(int w:graph[v]){
            if(color[w] == 0){
                color[w] = -color[v];
                if(!dfs(graph,w))
                    return false;
            }else if(color[w] == color[v]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        color = vector<int>(graph.size(),0);
        for(int i = 0 ; i < graph.size(); i++){
            if(color[i] == 0 ){
                color[i] = 1;
                if(!dfs(graph,i))
                    return false;

            }
        }
        return true;

    }
};