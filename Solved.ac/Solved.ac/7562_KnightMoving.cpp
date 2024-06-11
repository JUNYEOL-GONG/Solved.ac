#include <bits/stdc++.h>
using namespace std;

int T;
int length;
int curPosX, curPosY;
int destPosX, destPosY;

int board[305][305] = {};
bool visited_J[305][305] = {};
int dist[305][305] = {};

// ����Ʈ�� 8������ ����� ���� ������ �� �ִ�
int deltaCol[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int deltaRow[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

typedef pair<int, int> Pos;

int result = 0;

void Reset(int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			board[i][j] = 0;
			visited_J[i][j] = false;
			dist[i][j] = 0;
		}
	}
}

void BFS(int x, int y)
{
	queue<Pos> myQueue;
	myQueue.push(make_pair(x, y));
	visited_J[y][x] = true;
	dist[y][x] = 0;

	while (!myQueue.empty()) {
		Pos now = myQueue.front();
		myQueue.pop();

		for (int i = 0; i < 8; i++) {
			Pos next = make_pair(now.first + deltaCol[i], now.second + deltaRow[i]);
			if (next.first < 0 || next.first > length - 1 || next.second < 0 || next.second > length - 1)
				continue;
			if (visited_J[next.second][next.first])   // �̹� �湮�ߴٴ� ����, now���� next�� ���� �̹� ���ۿ� ������ ������ �ִ� �Ÿ��� ������� �ʴ´ٴ� ���� �ǹ��Ѵ�
				continue;
			myQueue.push(next);
			visited_J[next.second][next.first] = true;
			dist[next.second][next.first] = dist[now.second][now.first] + 1;

			if (next.first == destPosX && next.second == destPosY)
			{
				result = dist[next.second][next.first];
				return;
			}
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ����Ʈ�� �̵�

	cin >> T;
	while (T--) {
		cin >> length;
		cin >> curPosX >> curPosY;
		cin >> destPosX >> destPosY;

		BFS(curPosX, curPosY);

		cout << result << '\n';
		result = 0;

		Reset(length);
	}

	return 0;
}
