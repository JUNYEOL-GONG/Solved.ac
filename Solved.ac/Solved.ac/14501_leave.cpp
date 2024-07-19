#include <bits/stdc++.h>
using namespace std;

int N;
int duration[20];
int price[20];

int maxPrice = -1;

int dp[20];			// k��° ������ ����� ���� ���� �� �ִ� �ִ� ����

void DFS(int nowDay, int hasPrice) {
	// Ż�� ����
	if (nowDay >= N + 1) {
		maxPrice = max(maxPrice, hasPrice);
		return;
	}

	/// ��Ƽ����

	// ����� �� �� �ִ� ���
	if (nowDay + duration[nowDay] <= N + 1) {
		DFS(nowDay + duration[nowDay], hasPrice + price[nowDay]);
	}

	// ����� ���� �ʴ� ���
	DFS(nowDay + 1, hasPrice);
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ���

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> duration[i];
		cin >> price[i];
	}

	// 1. DFS(����Լ�)�� Ǯ �� �ִ�.
	// DFS(1, 0);
	// cout << maxPrice;

	// 2. Dynamic Programming(DP)�� Ǯ �� �ִ�.
	for (int day = 1; day <= N; ++day) {
		// ����� ������ �� �ִ� ���
		if (day + duration[day] <= N + 1) {
			int nextDay = day + duration[day];
			int nextPrice = dp[day] + price[day];
			dp[nextDay] = max(dp[nextDay], nextPrice);
		}
		// ����� �������� �ʰ� �Ϸ� ����
		dp[day + 1] = max(dp[day + 1], dp[day]);
	}

	// N + 1�ϱ����� �ִ� ������ ����մϴ�.
	cout << dp[N + 1];

	return 0;
}
