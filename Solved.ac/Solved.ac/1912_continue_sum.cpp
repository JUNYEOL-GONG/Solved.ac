#include <bits/stdc++.h>
using namespace std;

int n;
int sequence[100005];
int res = -0x7f7f7f7f;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ������

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	/*
	// 1. brute force
	// o(N^2) -> 100,000 x 100,000 = 10^10 = 100��
	// 1�ʿ� 1���ε� 100���̸� ���� �ȵǴ� ���귮�̴�
	for (int i = 0; i < n; i++) {		// start point
		int sum = arr[i];
		res = max(res, sum);
		for (int j = i + 1; j < n; j++) {	// next target point
			sum += arr[j];
			res = max(res, sum);
		}
	}
	*/

	// 2. dynamic programming
	// 10 -4 3 1 5 6 -35 12 21 -1
	// ������ �����µ� ���� ���� ��갪���� ũ��?
	// �׷��� �����ؼ� ����� ������ ����
	// �ֳ��ϸ� ���� ���� ���������ϴ� �� �̵��̱� �����̴�

	int curSum = 0;
	for (int i = 0; i < n; i++) {
		/*
		if (curSum + arr[i] < arr[i]) {
			curSum = arr[i];
		}
		else {
			curSum += arr[i];
		}
		*/
		curSum = max(curSum + sequence[i], sequence[i]); // ** ���� �ּ� �κ��� ��ü�� �� �ִ� �� ���� �ڵ� **
		res = max(res, curSum);
	}

	cout << res;

	return 0;
}
