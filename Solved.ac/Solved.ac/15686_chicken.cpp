#include <bits/stdc++.h>
using namespace std;

int N, M;
int city[55][55];
bool closed[55][55];
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
int minCityDist = 0x7f7f7f7f;

void CalcCityDistance()
{
	int cityDist = 0;
	// ������ ���� ��ȸ�ϸ鼭
	for (const auto& house : houses) {
		int chickenDist = 0x7f7f7f7f;
		// ġŲ������ �Ÿ��� ����Ѵ�
		for (const auto& chicken : chickens) {
			// ����� ���� �ǳʶڴ�
			if (closed[chicken.first][chicken.second]) continue;
			// ġŲ �Ÿ� ���
			int dist = std::abs(house.first - chicken.first) + std::abs(house.second - chicken.second);
			chickenDist = std::min(chickenDist, dist);
		}
		// ������ ġŲ �Ÿ� ���
		cityDist += chickenDist;
	}
	// ������ ġŲ �Ÿ� �ּڰ�
	minCityDist = std::min(minCityDist, cityDist);
}

/// <summary>
/// Recursive �Լ��� ��� ������ ġŲ�� ��� ������ �����ϴ� ������ �մϴ�
/// </summary>
/// <param name="closedCount"></param>
void Recursive(int closedCount)
{
	// ����� ġŲ�� ������ �Ϸ��ߴٸ�
	if (closedCount == chickens.size() - M) {

		// chickens.size()�� ġŲ�� ����
		// M�� ��Ƴ��� �� �ִ� ġŲ�� ����
		// chickens.size() - M�� ����� ġŲ�� ����

		CalcCityDistance();
		return;
	}

	// ġŲ���� ã�� �����Ų��
	for (int i = 0; i < chickens.size(); i++) {
		int r = chickens[i].first;
		int c = chickens[i].second;
		if (!closed[r][c]) {
			closed[r][c] = true;
			Recursive(closedCount + 1);
			closed[r][c] = false;
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ġŲ ���

	// �ð� ���⵵ ���
	// 1. 100 (���� ���� 2 * 50) x 13 (ġŲ���� ����) x 13C6 = �뷫 200��

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) houses.push_back({ i, j });
			else if (city[i][j] == 2) chickens.push_back({ i, j });
		}
	}

	Recursive(0);

	cout << minCityDist;

	return 0;
}
