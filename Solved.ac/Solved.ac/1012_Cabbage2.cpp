#include <bits/stdc++.h>
using namespace std;

int M, N, K;

int ground[55][55];
int visited_J[55][55];

int deltaCol[4] = { 0, 0, -1, 1 };
int deltaRow[4] = { -1, 1, 0, 0 };

int result = 0;

typedef pair<int, int> Pos;

// �׽�Ʈ ���̽��� �������̱� ������ ������ ����� �Ѵ�.
void Reset(int M, int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			ground[i][j] = 0;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			visited_J[i][j] = 0;
		}
	}
}

void BFS(int x, int y) {

	queue<Pos> myQueue;
	myQueue.push(make_pair(x, y));
	visited_J[y][x] = 1;

	int count = 0;

	while (!myQueue.empty()) {
		Pos now = myQueue.front();
		myQueue.pop();

		for (int i = 0; i < 4; i++) {
			Pos next = make_pair(now.first + deltaCol[i], now.second + deltaRow[i]);

			// �� ������ ��� ���
			if (next.second < 0 || next.second > N - 1 || next.first < 0 || next.first > M - 1)
				continue;
			// ���߰� �ɾ��� ���� �ƴ� ���
			if (ground[next.second][next.first] == 0)
				continue;
			// �湮�� ������ ���
			if (visited_J[next.second][next.first] == 1)
				continue;

			myQueue.push(make_pair(next.first, next.second));
			visited_J[next.second][next.first] = true;
		}

		count++;
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ����� ����
	// -> ���� ����

	int T; cin >> T;
	while (T--) {

		cin >> M >> N >> K;

		// �ʱ�ȭ
		for (int i = 0; i < K; i++) {
			int x, y; cin >> x >> y;
			ground[y][x] = 1;
		}

		// ��� ���� ���ƴٴϸ鼭 Flood Fill�� �����Ѵ�
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				// ���߰� �� �ɾ��� �ִ� ���
				if (ground[i][j] == 0)
					continue;
				// �̹� �湮�� ������ ���
				if (visited_J[i][j] == 1)
					continue;

				BFS(j, i);

				result++;
			}
		}

		cout << result << '\n';
		result = 0;

		Reset(M, N);
	}

	return 0;
}