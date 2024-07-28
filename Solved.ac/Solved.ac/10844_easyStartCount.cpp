#include <bits/stdc++.h>
using namespace std;

int N;
int dp[105][10];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ���� ��� ��

	cin >> N;

	// dp[i][j] : i�� ���̸� �����鼭 j�� ������ ��ܼ��� ����

	for (int i = 1; i <= 9; ++i)
	{
		/*
		dp[1][1] = 1;
		dp[1][2] = 1;
		dp[1][3] = 1;

		...

		*/

		dp[1][i] = 1;
	}

	for (int length = 2; length <= N; ++length)
	{
		for (int last = 0; last <= 9; ++last)
		{
			if (last == 0)
			{
				// ���� ������ 1�� ������ ��ܼ�

				dp[length][last] = dp[length - 1][1];
			}
			else if (last == 9)
			{
				// ���� ������ 8�� ������ ��ܼ�

				dp[length][last] = dp[length - 1][8];
			}
			else
			{
				// ���� ������ -1 or +1�� ������ ��ܼ�
				dp[length][last] = dp[length - 1][last - 1] + dp[length - 1][last + 1];
			}

			dp[length][last] %= 1000000000;
		}
	}

	int result = 0;

	for (int i = 0; i <= 9; ++i)
	{
		result += dp[N][i];
		result %= 1000000000;
	}

	cout << result;

	return 0;
}
