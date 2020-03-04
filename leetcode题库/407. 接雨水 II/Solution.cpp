// 关键是前戏，结构体啊，提前入队的点，优先队列（小顶堆）
// 关键就是外面往里面bfs，矮的碰到高的就可能产生积水，因为是取的最小的，所以当前值就是短板
// 与次平齐就是积水量
struct Cell {
	int x;
	int y;
	int height;
	Cell(int x, int y, int height) {
		this->x = x;
		this->y = y;
		this->height = height;
	}
	Cell() = default;
	bool operator()(Cell& c1, Cell& c2) {
		return c1.height > c2.height;
	}
};

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		int m = heightMap.size();
		if(m == 0) return 0;
		int n = heightMap[0].size();
		priority_queue<Cell, vector<Cell>, Cell> pq;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		vector<int> xoffset = {0,1,0,-1};
		vector<int> yoffset = {1,0,-1,0};
		for (int i = 0; i < m; i++) {
			pq.push(Cell(i,0,heightMap[i][0]));
			pq.push(Cell(i, n-1, heightMap[i][n-1]));
			visited[i][0] = visited[i][n - 1] = true;
		}
		for(int i = 1 ; i < n-1 ; i++)
		{
			pq.push(Cell(0, i, heightMap[0][i]));
			pq.push(Cell(m-1, i, heightMap[m-1][i]));
			visited[0][i] = visited[m-1][i] = true;
		}
		int res = 0;
		while (!pq.empty())
		{
			Cell cur = pq.top();
			pq.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nx = cur.x + xoffset[i];
				int ny = cur.y + yoffset[i];
				if(nx >=0 && nx <m && ny >=0 && ny < n && !visited[nx][ny])
				{
					visited[nx][ny] = true;
					res += max(0, cur.height - heightMap[nx][ny]);
					pq.push(Cell(nx, ny, max(cur.height, heightMap[nx][ny])));
				}
			}
			
			
		}

		return res;
	}
};