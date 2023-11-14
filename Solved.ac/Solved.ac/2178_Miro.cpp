#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct Position
{
	int x, y;

	Position()
		:x(0), y(0)
	{}
	Position(int _x, int _y)
		: x(_x), y(_y)
	{}

	bool operator == (const Position& pos) const
	{
		if (x == pos.x && y == pos.y)
			return true;

		return false;
	}
};

// �Է°�
int N, M;

// �̷� ��
int map[102][102];

// �̷� �湮 ����
int visited[102][102];

// �����¿� �迭
int dirX[4] = { 0,0,-1,1 };
int dirY[4] = { -1,1,0,0 };

// DFS�� ���� �ִ� �Ÿ�
int DFSLength = 100 * 100;

// BFS�� ���� �ִ� �Ÿ�
int BFSLength = 100 * 100;

Position curPos;
Position goalPos;

/// <summary>
/// DFS�� �ϸ� ���� �켱���� ��� ��θ� Ž���� �� �ִ�.
///	�ִ� �Ÿ��� ���ϴ� ���������� ��ȿ�����̴�. BFS�� �̿�����
/// </summary>
void DFS(Position pos, int depth)
{
	// ���� �Ѿ�� ����
	if (pos.x < 1 || pos.y < 1 || pos.x > M || pos.y > N)
		return;

	if (pos == goalPos)
	{
		if (DFSLength > depth)
			DFSLength = depth;

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		Position nextPos(pos.x + dirX[i], pos.y + dirY[i]);

		// �� �� �ִ�
		if (visited[nextPos.y][nextPos.x] == false && map[nextPos.y][nextPos.x] == true)
		{
			visited[nextPos.y][nextPos.x] = true;
			DFS(nextPos, depth + 1);
			visited[nextPos.y][nextPos.x] = false;
		}
	}
}

/// <summary>
/// BFS�� �̿��� �ʺ� �켱 Ž���� �����Ѵ�.
///	"�ִ� ���"�� Ž���ϴµ� ȿ�����̴�.
///	Queue�� �̿��Ѵ�
/// </summary>
void BFS(Position pos, int depth)
{

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// �̷� Ž�� ����

	cin >> N >> M;

	goalPos = { M,N };
	curPos = { 1, 1 };

	// ���� ��ġ�� �̹� �湮�� ����
	visited[curPos.y][curPos.x] = true;

	// �̷� ����
	for (int i = 1; i <= N; ++i)
	{
		string row; cin >> row;

		for (int j = 0; j < M; ++j)
		{
			if (row[j] == '1')
				map[i][j + 1] = 1;
		}
	}

	// DFS�� �̷� Ž��
	DFS(curPos, 1);

	// BFS�� �̷� Ž��
	BFS(curPos, 1);

	// �ִ� �Ÿ� ���
	cout << DFSLength << endl;

	return 0;
}