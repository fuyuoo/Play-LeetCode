// 考虑6种情况，bfs
class Solution {
    pair<int, int> op(int type, const pair<int, int> &state, int x, int y) {
        switch(type) {
            case 0 : return make_pair(x, state.second);
            case 1 : return make_pair(state.first, y);
            case 2 : return make_pair(0, state.second);
            case 3 : return make_pair(state.first, 0);
            case 4 :{
                int move = min(state.first, y-state.second);
                return make_pair(state.first - move, state.second + move);
            }
            case 5 : {
                int move = min(x-state.first, state.second);
                return make_pair(state.first + move, state.second - move);
            }
        }
        return make_pair(0,0);
    }
    struct HashPair {
        size_t operator()(const pair<int, int> &key) const noexcept
	    {
		    return size_t(key.first)*100000007 + key.second;
	    }
    };
public:
    bool canMeasureWater(int x, int y, int z) {
        unordered_set<pair<int,int>, HashPair> mark;
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        while(q.empty() == false) {
            auto f = q.front();
            q.pop();
            if(f.first + f.second == z) {
                return true;
            }
            for(int i = 0; i < 6; i++) {
                auto next = op(i, f, x, y);
                if(mark.find(next) != mark.end()) {
                    continue;
                }
                mark.insert(next);
                q.push(next);
            }
        }
        return false;
    }
};