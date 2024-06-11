#include <bits/stdc++.h>
using namespace std;

struct Pos
{
	int d, r, c;
	Pos(int _d, int _r, int _c)
	{
		d = _d;
		r = _r;
		c = _c;
	}
};

int M, N, H;

int box[105][105][105];
int dist[105][105][105];

int deltaDepth[6] = { -1, 1, 0, 0, 0, 0 };  // depth
int deltaRow[6] = { 0, 0, 0, 0, -1, 1 };    // row
int deltaCol[6] = { 0, 0, -1, 1, 0, 0 };    // col

queue<Pos> q;

int minDuration = -1;

void Make_Box()
{
	cin >> M >> N >> H;

	for (int depth = 0; depth < H; depth++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				cin >> box[depth][row][col];
			}
		}
	}
}

void BFS() {
	while (!q.empty()) {
		auto now = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			auto next = Pos(now.d + deltaDepth[i], now.r + deltaRow[i], now.c + deltaCol[i]);
			if (next.d < 0 || next.d > H - 1 || next.r < 0 || next.r > N - 1 || next.c < 0 || next.c > M - 1) continue;
			if (box[next.d][next.r][next.c] != 0) continue;
			dist[next.d][next.r][next.c] = dist[now.d][now.r][now.c] + 1;
			box[next.d][next.r][next.c] = 1;
			q.push(next);
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : �丶��
	// ��ĥ�� ������ �丶����� ��� �ʹ���
	// �� �ּ� �ϼ��� ���ϴ� ���α׷�

	Make_Box();

	// ����, ����� ������ ��� �丶�䰡 �;��ִ� ����(1)�̸� 0�� ����ؾ� �Ѵ�.
	bool isAllMature = true;
	for (int depth = 0; depth < H; depth++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				// �� �;��ִ� �丶�䰡 �ִ��� Ȯ���Ѵ�
				if (box[depth][row][col] == 0)
					isAllMature = false;
			}
		}
	}

	if (isAllMature)
	{
		cout << 0;
		return 0;
	}

	for (int depth = 0; depth < H; depth++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				// �;��ִ� �丶�䰡 �ִٸ� ť�� �ִ´�
				if (box[depth][row][col] == 1)
					q.emplace(depth, row, col);
			}
		}
	}

	BFS();

	// �丶�䰡 ��� ������ ���ϴ� ��Ȳ�̸� -1�� ����ؾ� �Ѵ�.
	bool isNeverMature = false;
	for (int depth = 0; depth < H; depth++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				// �� �;��ִ� �丶�䰡 �ִ��� Ȯ���Ѵ�
				if (box[depth][row][col] == 0)
					isNeverMature = true;
			}
		}
	}

	if (isNeverMature)
	{
		cout << -1;
		return 0;
	}

	for (int depth = 0; depth < H; depth++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				// �ִ� �Ⱓ�� ���Ѵ�
				minDuration = max(minDuration, dist[depth][row][col]);
			}
		}
	}

	cout << minDuration;

	return 0;
}