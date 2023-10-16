#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> vec;

	// n���� ������ �̷���� ������ ������ �־�����
	for (int i = 0; i < n; ++i)
	{
		int value; cin >> value;
		vec.push_back(value);
	}

	// �� ���� ���� �����ؼ� ���� �� �ִ� �� �� ���� ū ��
	// �� �� �̻� ����
	// 10, -4, 3, 1, 5, 6, -35, 12, 21, -1
	// 12 + 21�� 33

	/*
	* ��� 1 : Brute Force (�ð� ���⵵ O(n^2))*
	int sum = 0;
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			// ��� ��츦 ������ �� �غ���,,
			// 1 ~ n , 2 ~ n , 3 ~ n , ...
			sum += vec[j];
			res = std::max(sum, res);
		}

		sum = 0;
	}

	cout << res << endl;
	*/

	/*
	* ��� 2 : ������ ������ ��� ���� (�����ؼ� �߸� ǰ) *
	int curSum = 0;
	int maxSum = 0;
	for (int i = 0; i < n; ++i)
	{
		curSum += vec[i];
		maxSum = std::max(curSum, maxSum);

		// ���� �ϳ� ������ ��
		// * ������ ���´ٰ� ������ �����Ұ� �ƴϳ�,, �����ߴ� *
		if (vec[i] < 0)
			curSum = 0;
	}

	cout << maxSum << endl;
	*/

	// Dynamic Programming (���� ���α׷���)�� �̿��� Ǯ�� ���
	// (�ð� ���⵵ O(n))
	// DP�� ���� ���� "����ؼ� Ǯ��"�̴�.

	int curSum = vec[0];
	int maxSum = vec[0];

	for (int i = 1; i < n; ++i)
	{
		// ** �Ʒ� ��츦 �Ǵ� **
		// 10 -4 3 => 10 - 4�� 3���� ũ��
		// 3 1 5 6 -35 12 => 3 + 1 + 5 + 6 - 35�� 12���� �۴�
		curSum = std::max(vec[i], curSum + vec[i]);
		maxSum = std::max(maxSum, curSum);
	}

	cout << maxSum << endl;

	return 0;
}