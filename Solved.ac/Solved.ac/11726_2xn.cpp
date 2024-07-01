#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1005];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 2��n Ÿ�ϸ�

	// dp ���̺� �����ϱ�
	// dp[i] = 2 x i�� ���簢���� ä��� ����� ��

	// ��ȭ�� ã��
	// 2 x n�� ���簢���� ���� ��, left-top�� ĭ�� �������� ���캸��
	// 2 x 1�� ���簢���� ���� �����
	// 1 x 2�� ���簢���� ���� ����� �ִ�.
	// 1 x 2�� ���簢���� ���� ��쿡��, �� �Ʒ��� 1 x 2�� ���簢�� �ۿ� ���� �� ����.
	// ����  dp[i] = dp[i-1] + dp[i-2]�� �ȴ�

	// �ʱ갪��
	// dp[1]�� dp[2]�� ���ϸ�, dp[i] = dp[i-1] + dp[i-2]�� ������ų �� �ִ�.

	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;	// int over flow �߻��� ���� ���� ������ ���� ����ؼ� ��������
		// dp[i] = (dp[i - 1] % 10007 + dp[i - 2] % 10007) % 10007; // ��ⷯ ������ �й��Ģ (�ʿ������ ����)
	}
	cout << dp[n];

	return 0;
}
