#include <bits/stdc++.h>
using namespace std;


int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ��� ������

	// ���ӿ��� ���� �� �ִ� �� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	// ù ��° ����� ������ ��ƾ� �Ѵ�
	// ���ӵ� �� ����� ���� �� ����
	// �ѹ��� �� ĭ Ȥ�� �� ĭ �ö� �� �ִ�
	// ������ ����� �ݵ�� ��ƾ� �Ѵ�

	int N; cin >> N;
	int stairs[305];	// stairs[i] = i�� ����� ����
	for (int i = 1; i <= N; i++) {
		cin >> stairs[i];
	}
	int dp[305];		// dp[i] = i�� ��� ������ �ִ�
	dp[0] = 0;
	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];
	// dp[3]
	// 0 -> 1 -> 3
	// 0 -> 2 -> 3
	dp[3] = std::max(dp[1] + stairs[3], dp[0] + stairs[2] + stairs[3]);

	// ������ ����� �ݵ�� ��ƾ� �Ѵ�
	// ����� �� ��� Ȥ�� �� ��ܾ� ���� �� �ִ�.
	// ���ӵ� ������ ����� ������ �ȵȴ�.
	//
	// 1 -> 2
	// 1 -> 3
	//
	// 1 -> 4 (x)
	// 1 -> 2 -> 3 (x)
	//
	// 4 -> 5 -> 6 (x)
	// 3 -> 6 (x)
	//
	// 3 -> 5 -> 6 (�� ĭ �پ��ٰ� �� ĭ �پ ���� ��)
	// 4 -> 6 (�� ĭ �پ ���� ��)
	//
	// dp[4] + stairs[6]
	// vs
	// dp[5] + stairs[6]
	// �߿��� �� ū ��

	for (int i = 4; i <= N; i++) {
		int a = dp[i - 2] + stairs[i];						// i - 2 -> i
		int b = dp[i - 3] + stairs[i - 1] + stairs[i];		// i - 3 -> i - 1 -> i		// dp[i-1] + stairs[i] �� �ϸ� �ȵǴ� ����: ���ӵ� �� ���� ����� ���� �� �ֱ� ������ �� ���� �� ĭ �ٰ� �� ĭ �پ���� �Ѵ�
		dp[i] = std::max(a, b);
	}

	cout << dp[N];

	return 0;
}
