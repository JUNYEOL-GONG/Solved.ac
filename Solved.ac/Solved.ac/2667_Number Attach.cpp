#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int visited[26][26];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0,0 };

struct Position
{
	int x, y;

	Position(int _x, int _y)
		: x(_x), y(_y)
	{}
};

void BFS(std::vector<std::vector<char>>& map, Position pos)
{
	std::queue<Position> myQueue;
	myQueue.push(pos);

	while (!myQueue.empty())
	{
		for (int k = 0; k < 4; ++k)
		{
			Position nextPos(myQueue.front().x + dx[k], myQueue.front().y + dy[k]);
			if (map[nextPos.y][nextPos.x] == '1')
			{
				cout << "(" << nextPos.x << ", " << nextPos.y << ")" << endl;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ���� ��ȣ ���̱�

	int N; cin >> N;

	std::vector<std::vector<char>> map(N + 1);
	for (auto& vec : map)
		vec.resize(N + 1);

	// Map ����
	for (int i = 1; i <= N; ++i)
	{
		string input; cin >> input;

		for (int j = 1; j <= N; ++j)
		{
			map[i][j] = input[j - 1];
		}
	}

	// 1. n x n�� Map�� (1,1)���� (n,n)���� ��ȸ�Ѵ�.
	// 2. ��ȸ �ϸ鼭 1�� ã�� ���� ����Ʈ ������ ���Ѵ�
	// 3. ���̻� ������ ���ٸ� ��� �湮ó���� �Ͽ� �� ����Ʈ ������ ������ �Ѵ�
	// 4. ��ȸ�� �������� �ٽ� (1)�� �������� ������Ѵ�.
	// 5. �׷��� ������ ��, ������ ���� ���� ���Ѵ� (�������� ����)

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			// ����Ʈ ã��
			if (map[i][j] == '1' && visited[i][j] != true)
			{
				Position searchPos(j, i);

				// DFS�� �����¿� ������ Ž���ϱ� ����
				BFS(map, searchPos);
			}
		}
	}

	return 0;
}