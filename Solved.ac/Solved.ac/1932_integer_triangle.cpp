#include <bits/stdc++.h>
using namespace std;

int n;
int triangle[505][505];
int dp[505][505];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ���� �ﰢ��

	// dp[i][j] == (i,j) ���� ���� ���� ������ ���� ���
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}
	dp[1][1] = triangle[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
		}
	}

	// dp[n]���� ���� ū ���� ã�´�
	int res = -0x7f7f7f7f;
	for (int i = 1; i <= n; i++) {
		res = max(res, dp[n][i]);
	}

	cout << res;

	return 0;
}
