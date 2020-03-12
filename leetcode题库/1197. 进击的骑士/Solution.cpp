class Solution
{
public:
	int minKnightMoves(int x, int y)
	{
        if(x == 0 && y == 0)
            return 0;
		int xoffset[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
		int yoffset[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
		queue<vector<int>> pq;
		
		unordered_map<int,int> visited;
		pq.push({ x, y, 0 });
		while (!pq.empty())
		{
			vector<int> cur = pq.front();
			pq.pop();
			int xx = cur[0];
			int yy = cur[1];
			for (int i = 0; i < 8; ++i)
			{
				int nx = xx + xoffset[i];
				int ny = yy + yoffset[i];
				if (nx == 0 && ny == 0)
					return cur[2] + 1;
				else if (visited[nx*1000 + ny] == false &&(xx * xx + yy * yy - nx * nx - ny * ny >= 0 || (nx * nx + ny * ny) < 18))
				{
					visited[nx * 1000 + ny] = true;
					pq.push({ nx, ny, cur[2] + 1 });
				}
			}
		}
		return -1;;
	}
};