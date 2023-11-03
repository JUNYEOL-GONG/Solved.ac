#include <iostream>

using namespace std;

int main()
{
	// ���������� �ּ� ������ ����ؼ� ����

	///  Greedy�� ������ ��, "������ �ſ� �����ϰ� �ٲ� �� �ִ� ������ ����"�� �ִ����� �� ã�ƺ��� ������ ������.
	///	 "�ּ� ������ ���ؼ�, �� �����Ҹ� ���������� ���� �� ������ ���ؾ� �Ѵ�."

	int n; cin >> n;

	long long dist[100000];
	long long cost[100001];

	for (int i = 1; i < n; ++i)
		cin >> dist[i];

	for (int i = 1; i <= n; ++i)
		cin >> cost[i];

	// �ִ��� �� ������ ���� ��־� �Ѵ�.
	long long res = 0;
	long long minCost = 99999999999;	// 10�� �̻��̾�� �Ѵ�. (10����� ������ ������ �� �ֱ� ����)

	/// ������ �����ϰ� �����ϴ� ���� �ٽ����� �κ�
	// n -1 ������ �����ұ����� �����ϸ� �ȴ�
	for (int i = 1; i < n; ++i)
	{
		if (cost[i] < minCost)
			minCost = cost[i];

		/// ���� ���������� �����÷ο� ����
		res += minCost * dist[i];
	}

	cout << res << '\n';

	return 0;
}