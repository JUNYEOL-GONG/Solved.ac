#include <bits/stdc++.h>
using namespace std;

int R, C;

string maze[1005];		// ������ ������� �ʰ� ���ڿ��� �پ��ֱ� ������, ��ü������ char[] ���ڿ��� string �ڷ����� ����Ѵ�
int dist1[1005][1005];	// ���� ���� �ð�
int dist2[1005][1005];	// �������� �̵� �ð�

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ��!

	// #: ��
	// .: ������ �� �ִ� ����
	// J: �������� �ʱ� ��ġ
	// F: ���� ��ġ (���� �� ����)

	// �����̰� ���� �����ϱ� ���� �̷θ� Ż�� �� �� ���� ��� IMPOSSIBLE �� ����Ѵ�.
	// �����̰� �̷θ� Ż���� �� �ִ� ��쿡�� ���� ���� Ż��ð��� ����Ѵ�.

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		// R�࿡ C���� ���� -1�� ä���
		fill(dist1[i], dist1[i] + C, -1);
		fill(dist2[i], dist2[i] + C, -1);
	}
	for (int i = 0; i < R; i++) {
		cin >> maze[i];
	}
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (maze[i][j] == 'F') {
				q1.push({ j, i });
				dist1[i][j] = 0;
			}
			if (maze[i][j] == 'J') {
				q2.push({ j, i });
				dist2[i][j] = 0;
			}
		}
	}
	// �ҿ� ���� BFS (���� ��� ��ο� ���� �̵��� ��ģ��. �� �������� �ð��� ����ϰ� �������� �̵� �ð��� ���Ѵ�)
	while (!q1.empty()) {
		auto now = q1.front(); q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nextX = now.first + dx[dir];
			int nextY = now.second + dy[dir];
			if (nextX < 0 || nextX >= C || nextY < 0 || nextY >= R) continue;
			if (maze[nextY][nextX] == '#' || dist1[nextY][nextX] >= 0) continue;
			dist1[nextY][nextX] = dist1[now.second][now.first] + 1;
			q1.push({ nextX, nextY });
		}
	}
	// �����̿� ���� BFS
	while (!q2.empty()) {
		auto now = q2.front(); q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nextX = now.first + dx[dir];
			int nextY = now.second + dy[dir];
			if (nextX < 0 || nextX >= C || nextY < 0 || nextY >= R) {
				cout << dist2[now.second][now.first] + 1;
				return 0;
			}
			if (dist2[nextY][nextX] >= 0 || maze[nextY][nextX] == '#') continue;
			if (dist1[nextY][nextX] != -1 && dist1[nextY][nextX] <= dist2[now.second][now.first] + 1) continue; // ���� ���� �ð��� ����Ѵ� (�̹� ���������� �� �� ����)
			dist2[nextY][nextX] = dist2[now.second][now.first] + 1;
			q2.push({ nextX, nextY });
		}
	}

	cout << "IMPOSSIBLE"; // ���⿡ �����ߴٴ� ���� Ż�⿡ ���������� �ǹ�.

	return 0;
}
