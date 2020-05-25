// 使用双向链表和哈希表的数据结构完成，存取都是O(1)
// 关键点在于哈希表存储的值是双向链表中的迭代器
class LRUCache
{
private:
	int _capacity;
	list<pair<int, int>> _list;
	unordered_map<int, list<pair<int, int>>::iterator> _map;
public:
	LRUCache(int capacity)
	{
		_capacity = capacity;
	}

	int get(int key)
	{
		int res = -1;
		if (_map.count(key))
		{
			res = _map[key]->second;
			_list.erase(_map[key]);
			_list.emplace_front(key, res);
			_map[key] = _list.begin();
		}

		return res;
	}

	void put(int key, int value)
	{
		if (_map.count(key))
		{
			_list.erase(_map[key]);
		}
		else if(_list.size() == _capacity)
		{
			_map.erase(_list.back().first);
			_list.pop_back();
		}
		_list.emplace_front(key, value);
		_map[key] = _list.begin();

			
	}
};