#include <bits/stdc++.h>
using namespace std;

int N;
pair<long long, long long> dp[100];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ��ģ��

	cin >> N;

	// dp[i] = i�ڸ� ��ģ���� �� 0���� ������ �� 1�� ������ ����

	dp[1] = { 0, 1 };
	// dp[2] = { 1, 0 };
	// dp[3] = { 1, 1 };
	// dp[4] = { 2, 1 };
	// dp[5] = { 3, 2 };
	// dp[6] = { 5, 3 };

	// 0���� �����ִ��Ŵ� 0�� 1�� �ٲ�
	// 1�� �����ִ��Ŵ� 0���� �ٲ�

	// ���������� 0���� �����ִ� ������ prev_left + prev_right
	// ���������� 1�� �����ִ� ������ prev_left

	// long long�� ����ؾ� �����÷ο찡 �߻����� �ʴ´�

	for (int i = 2; i <= N; i++) {
		dp[i] = { dp[i - 1].first + dp[i - 1].second, dp[i - 1].first };
	}

	cout << dp[N].first + dp[N].second;

	return 0;
}
