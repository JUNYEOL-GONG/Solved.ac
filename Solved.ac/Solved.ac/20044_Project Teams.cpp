#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Project Teams

	// �� �л����� �ڵ� ������ ��� �ٸ���.
	// ���� �ڵ� ������ ���� �ִ��� �����ϰ� ����
	// �л����� 2n

	// �ð� ���� : 0.5��
	// N : 2 * n = 10,000ȸ
	// -> 0.5�� ���� 5õ���� ���� ���� ����
	// -> 10000 * 10000 = 1���̹Ƿ� O(N^2) �˰������� ���� �Ұ���
	// -> O(N) or O(NlogN) ����

	int n; cin >> n;
	int arr[10001];

	for (int i = 1; i <= 2 * n; ++i)
		cin >> arr[i];

	// '���� ū �ڵ������� ���� ���� ������ ���� ���ϱ� ���� ������ �ʿ�'
	// �ڵ� ���� �������� ����
	std::sort(arr + 1, (arr + 2 * n) + 1);

	// min���� ����� Ŀ���Ѵ�.
	// �� �л��� �ڵ� ������ ���� min���� ���� ��츸 �ִ� ��� min�� ���� �ùٸ��� �ʰ� ��µȴ�.
	int min = arr[1] + arr[2 * n];

	for (int i = 1; i <= 2 * n; ++i)
	{
		if (min >= (arr[i] + arr[2 * n - i + 1]))
			min = arr[i] + arr[2 * n - i + 1];
	}

	cout << min << endl;

	return 0;
}