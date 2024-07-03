#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[1005];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 2 x n Ÿ�ϸ� 2

	// ������ ���ǿ��� 10007�� ���� �������� ����϶�� �� ������ ���ؼ� �����غ���
	// �׷��� �� ���꿡�� 10007�� �����ϵ��� ���������� �� �� �ִ�.

	// ������ ������ ����
	// (a + b) % c = ( (a % c) + (b % c) ) % c (��ⷯ ������ �й� ��Ģ ����)

	cin >> n;

	// dp[i] = 2 x i�� ���簢���� 1 x 2, 2 x 1, 2 x 2 Ÿ�Ϸ� ä��� ����� ��
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2]) % 10007;
	}

	cout << dp[n];

	return 0;
}
