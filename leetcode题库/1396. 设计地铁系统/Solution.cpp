// 主要使用哈希表，关键
class UndergroundSystem {
private:
	unordered_map<int, pair<string, int>> recordtmp;
	unordered_map<string, unordered_map<string,pair<int,int>>> map;
public:
	UndergroundSystem() {

	}

	void checkIn(int id, string stationName, int t) {
		recordtmp[id] = make_pair(stationName, t);
	}

	void checkOut(int id, string stationName, int t) {
		auto pair = recordtmp[id];
		recordtmp.erase(id);
		map[pair.first][stationName].first++;
		map[pair.first][stationName].second += (t - pair.second);


	}

	double getAverageTime(string startStation, string endStation) {
		auto pair = map[startStation][endStation];
		return double(pair.second) / pair.first;
	}
};