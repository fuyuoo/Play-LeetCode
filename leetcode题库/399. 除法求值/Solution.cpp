// 转化为有向有权图就简单了
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string, double>> g;
        for(int i = 0 ; i < equations.size() ; i++){
            g[equations[i][0]][equations[i][1]] = values[i];
            g[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }
        vector<double> res;
        for(int i = 0 ; i < queries.size() ; i++){
            res.emplace_back(getVal(g,queries[i][0],queries[i][1]));
        }
        return res;
    }
private:
    double getVal(unordered_map<string,unordered_map<string, double>>& g,string begin,string end){

        unordered_map<string,bool> visited;
        if(g.find(begin) == g.end() ||g.find(end) == g.end() )
            return -1.0;
        if(begin == end)
            return 1.0;

        queue<pair<string,double>> q;
        q.push({begin,1.0});

        while(!q.empty()){
            pair<string, double> v = q.front();
            visited[v.first] = true;
            if(v.first == end)
                return v.second;
            q.pop();
            for(auto w : g[v.first]){
                if(!visited[w.first])
                    q.push({w.first,v.second * w.second});
            }
        }
        return -1;
    }

};