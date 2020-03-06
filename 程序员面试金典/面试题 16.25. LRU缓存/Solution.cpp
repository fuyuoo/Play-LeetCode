class LRUCache {
private:
	unordered_map<int, list<pair<int, int>>::iterator> map;  // 存key 和所在的位置
	list<pair<int, int>> data;   // 存key 和 val
	int capacity;
public:

	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		auto t = map.find(key);
		if (t == map.end())
			return -1;
		else {
			// 放置的位置，数据源，迭代器
			data.splice(data.begin(), data, t->second);   // 因为存的是迭代器，所以可以实现O(1)时间找到
			return t->second->second;
		}
	}

	void put(int key, int value) {
		int t = get(key);
		if (t == -1) {      //not found
			if (data.size() == capacity) {
				map.erase(data.back().first);
				data.pop_back();
			}
			data.emplace_front(key, value);
			map[key] = data.begin();
		}
		else {
			data.pop_front();
			data.emplace_front(key, value);
			map[key] = data.begin();
		}
	}
};