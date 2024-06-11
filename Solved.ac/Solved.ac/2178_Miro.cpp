#include <iostream>
#include <string>
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
int visited_J[102][102];

// �����¿� �迭
int dirX[4] = { 0,0,-1,1 };
int dirY[4] = { -1,1,0,0 };

// DFS�� ���� �ִ� �Ÿ�
int DFSLength = 100 * 100;

// BFS�� ���� �ִ� �Ÿ�
int BFSLength = 100 * 100;

// BFS �Ÿ� ��
int distMap[102][102];

Position curPos;
Position goalPos;

ostream& operator << (ostream& os, Position pos)
{
	os << "(" << pos.x << " " << pos.y << ") ";

	return os;
}

void PrintQueue(std::queue<Position> myQueue)
{
	system("cls");

	// ť�� �ִ� ��� ��Ҹ� ���
	while (!myQueue.empty())
	{
		std::cout << myQueue.front();
		myQueue.pop();
	}

	cout << endl;
}

/// <summary>
/// DFS�� �ϸ� ���� �켱���� ��� ��θ� Ž���� �� �ִ�.
///	�ִ� �Ÿ��� ���ϴ� ���������� ��ȿ�����̴�. BFS�� �̿�����
/// </summary>
void DFS(Position pos, int depth)
{
	// ���� �Ѿ�� ����
	if (pos.x < 1 || pos.y < 1 || pos.x > M || pos.y > N)
		return;

	// ��ǥ ���� ���� ��, �Ÿ� ����
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
		if (visited_J[nextPos.y][nextPos.x] == false && map[nextPos.y][nextPos.x] == true)
		{
			visited_J[nextPos.y][nextPos.x] = true;
			DFS(nextPos, depth + 1);

			// ������ ��θ� �ٽ� �ʱ�ȭ
			visited_J[nextPos.y][nextPos.x] = false;
		}
	}
}

/// <summary>
/// BFS�� �̿��� �ʺ� �켱 Ž���� �����Ѵ�.
///	"�ִ� ���"�� Ž���ϴµ� ȿ�����̴�.
///	Queue�� �̿��Ѵ�
/// </summary>
int BFS(Position startPos)
{
	// Queue�� �̿��� �ִ� ��� Ž�� (���� Ž��)
	std::queue<Position> myQueue;

	// ������ ����
	myQueue.push(startPos);
	visited_J[startPos.y][startPos.x] = true;
	distMap[startPos.y][startPos.x] = 1;

	// ť�� ���� �ִ� ���� ����ؼ� �ݺ�
	while(!myQueue.empty())
	{
		// �� ��ġ���� �� �� �ִ� ��� ������ Ž���Ѵ�.
		// ����� ���
		for (int i = 0; i < 4; ++i)
		{
			// ������ �̵��� ��ġ ���
			Position nextPos(myQueue.front().x + dirX[i], myQueue.front().y + dirY[i]);

			// �� �� �ִٸ�
			if (visited_J[nextPos.y][nextPos.x] == false && map[nextPos.y][nextPos.x] == true)
			{
				// Queue�� �־�д�.
				myQueue.push(nextPos);

				// �湮 ó��
				visited_J[nextPos.y][nextPos.x] = true;

				// �Ÿ� ��� (����)
				distMap[nextPos.y][nextPos.x] = distMap[myQueue.front().y][myQueue.front().x] + 1;
			}
			else
				continue;
		}

		// �� �������� �� �տ� �ִ� ��� ����
		myQueue.pop();
	}

	return distMap[N][M];
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
	visited_J[curPos.y][curPos.x] = true;

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

	// DFS �ִ� �Ÿ� ���
	cout << DFSLength << endl;

	// BFS�� �̷� Ž��
	BFSLength = BFS(curPos);

	// BFS �ִ� �Ÿ� ���
	cout << BFSLength << endl;

	return 0;
}