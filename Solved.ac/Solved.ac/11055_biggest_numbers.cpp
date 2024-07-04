#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1005];
int dp[1005];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ���� ū �����ϴ� �κ� ����

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = arr[i];	// �ʱ�ȭ
	}

	// dp[i]: i��ұ����� �ִ� �κ����� �����صд� ** ù°: �� �߻� ��ƴ� **

	// O(N^2)������ N = 1000�̱� ������ 1�� �ȿ� ����� �ذ��� �� �ִ�
	// 10^6 = 100�� -> 1�� �ȿ� �� ����

	// i ��Ҹ� ������ ��ҷ� �ΰ�
	for (int i = 0; i < N; i++) {
		// �տ� �ִ� ��ҵ��� �κ����� �����Ѵ�
		for (int j = 0; j < i; j++) {
			// ���� ��쿡�� �κ��� ���
			if (arr[i] > arr[j]) {
				// j��Ұ� i��Һ��� �۱� ������, ���������� dp[i]�� ���ϱ� ���� dp[j]�� ���� ����� �� �ִ� ���̴�.. ** ��°: �� �߻��� �� ��ƴ� **
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
	}

	std::cout << *max_element(dp, dp + N);

	return 0;
}
