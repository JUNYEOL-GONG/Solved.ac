#include <bits/stdc++.h>
using namespace std;

int N;
int sequence[1005];
int dp[1005];

int longest_increasing_subsequence(const int* arr) {

	// dp[i]: i��° ���Ҹ� ������ ���ҷ� �ϴ� ���� �� �����ϴ� �κ� ������ ����
	// 
	// dp[1]: 1
	// dp[2]: 2
	// dp[3]: 1
	// dp[4]: 3
	// dp[5]: 2
	// dp[6]: 4

	std::fill(dp + 1, dp + N + 1, 1);

	// O(N^2)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {	// j�� i���� �� ĭ �������� Ž���ؾ� �ϹǷ� j < i
			// �� �κ��� �ٽ��̴�
			// dp[i]: i��° ���ұ����� ���� ���� LIS ����
			// dp[j] + 1: j��° ���ұ����� LIS�� '���� i��° ���Ҹ� �߰�'�� ����
			if (arr[i] > arr[j]) {	// 1 ~ i���� �� ���� ���ҿ� ���ؼ��� üũ
				// [10 20 10 30 20 50] �� �־����� ��
				// i�� 4��� 4��° ���� 30�� ��������,
				// ** 10, 20 10������ LIS�� + 1 �� ���� ū ���� dp[i]�� �Ѵ� **
				// * ���� �ϳ��� ���ٸ� dp[i]�� �⺻�� (1)�� ����Ѵ� *
				// �� ��� ������ �� ���ٷ� �����ȴ�..
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	return *max_element(dp + 1, dp + N + 1);
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ���� �� �����ϴ� �κ� ���� (LIS ����: Longest Increasing SubSequence)

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> sequence[i];
	}
	cout << longest_increasing_subsequence(sequence);

	return 0;
}
