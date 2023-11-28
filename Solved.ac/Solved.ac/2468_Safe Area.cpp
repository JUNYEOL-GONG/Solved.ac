#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Position
{
	int x, y;

	Position(int _x, int _y)
		:x(_x), y(_y)
	{}

	bool operator == (Position pos)
	{
		return pos.x == x && pos.y == y;
	}
};

int N;

int map[100][100];
int visited[100][100];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void DFS()
{

}

void BFS(int y, int x)
{
	Position curPos(x, y);
	std::queue<Position> myQueue;
	myQueue.push(curPos);
	visited[curPos.y][curPos.x] = 1;

	while(!myQueue.empty())
	{
		for(int i=0; i<4; ++i)
		{
			Position nextPos(myQueue.front().x + dx[i], myQueue.front().y + dy[i]);

			if (nextPos.x < 0 || nextPos.x >= N || nextPos.y < 0 || nextPos.y >= N)
				continue;

			if (visited[nextPos.y][nextPos.x] == 0)
			{
				curPos = nextPos;
				myQueue.push(curPos);
				visited[curPos.y][curPos.x] = 1;
			}
		}

		myQueue.pop();
	}
}

void Reset()
{
	for(int i=0; i<100; ++i)
	{
		for(int j=0; j<100; ++j)
		{
			visited[i][j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ���� ����

	cin >> N;

	// map ����
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];
		}
	}

	int maxCnt = -99999999;

	// rain�� �ƿ� ���� �ʴ� ��� ~ �ִ� ���̰� ���� ���
	for(int rain = 0; rain <= 100; ++rain)
	{
		int cnt = 0;

		// rain�� ���� map�� visited �ʱ� ����
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (map[i][j] <= rain)
					visited[i][j] = 1;
				else
					visited[i][j] = 0;
			}
		}

		// SafeArea ���
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (visited[i][j] == 0)
				{
					BFS(i, j);
					cnt++;
				}
			}
		}

		maxCnt = std::max(maxCnt, cnt);

		Reset();
	}

	cout << maxCnt << '\n';

	return 0;
}