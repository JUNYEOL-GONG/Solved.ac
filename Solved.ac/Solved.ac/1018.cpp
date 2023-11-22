#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Position
{
	int x, y;
	Position(int _x, int _y)
		:x(_x), y(_y)
	{}
};

char board[51][51];

/// <summary>
/// �»�� ��������
/// </summary>
/// <returns></returns>
int ChessBoard(Position topLeft)
{
	Position curPos(topLeft.x, topLeft.y);
	int cnt = 0;

	// �� ����� �غ���
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			Position nextPos(curPos.x + 1, curPos.y);
			if (board[curPos.y][curPos.x] == board[nextPos.y][nextPos.x])
				cnt++;

			curPos = nextPos;
		}

		curPos.y += 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ü���� �ٽ� ĥ�ϱ�

	int N, M;
	cin >> N >> M;

	// ���� ����
	for (int i = 1; i <= N; ++i)
	{
		string row; cin >> row;

		for (int j = 1; j <= M; ++j)
		{
			board[i][j] = row[j - 1];
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			Position topLeft(i, j);
			ChessBoard(topLeft);
		}
	}

	return 0;
}