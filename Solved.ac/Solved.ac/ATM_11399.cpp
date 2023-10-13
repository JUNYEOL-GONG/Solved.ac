#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	int partialSum = 0;
	int res = 0;

	std::vector<int> timeVec(N + 1);

	for (int i = 1; i <= N; ++i)
		cin >> timeVec[i];

	// atm 1�뿡 n���� ���� ��
	// n���� 1������ n������ ��ȣ�� �Ű���
	// ** ���� ���� ������ ���� ���� �ð����� �޶��� **
	// 3 1 4 3 2�� ��� = 39��
	// 1 2 3 3 4�� ��� = 32��
	// ���� �����ϴµ� �ʿ��� �ð��� ���� �ּҰ� ���ϱ�

	// �����ϴ� �ð��� ���� ������� ���� �����ؾ� �Ѵ�.
	std::sort(timeVec.begin(), timeVec.end());

	for (int i = 1; i <= N; ++i)
	{
		partialSum += timeVec[i];
		res += partialSum;
	}

	cout << res << endl;

	return 0;
}