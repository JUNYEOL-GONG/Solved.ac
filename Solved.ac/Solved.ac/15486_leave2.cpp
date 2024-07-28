#include <bits/stdc++.h>
using namespace std;

int N;
int t[1500005];     // 150�� x 4Byte = 6,000,000 BYTE => 5859 KB => 5.7 MB (�� ������ ������������ ���� ����)
int p[1500005];
int dp[1500005];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ��� 2

	cin >> N;       // N�� �ִ� 1,500,000

	for (int i = 1; i <= N; ++i)
	{
		cin >> t[i] >> p[i];
	}

	for (int now = 1; now <= N; ++now)
	{
		/// ����� ������ ��Ȳ�� �ǵ� �ȵǵ�, ���� ���� ���� �Ѿ ���
		dp[now + 1] = max(dp[now + 1], dp[now]);

		// ���� ��¥���� ����� ������ ��, ��� ���� �������� ����� ������ ���
		if (now + t[now] <= N + 1)
		{
			int nextDay = now + t[now];
			int nextPrice = dp[now] + p[now];

			dp[nextDay] = max(dp[nextDay], nextPrice);
		}
	}

	cout << dp[N + 1];

	return 0;
}
