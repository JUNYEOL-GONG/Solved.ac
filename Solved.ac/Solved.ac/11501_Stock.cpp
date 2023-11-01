#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
	 * t : �׽�Ʈ ���̽� Ƚ��
	 * n : ��¥ ��
	 */

	 // �ֽ�

	// �ִ� ���� : 1,000,000�� * 10,000�� = 100���
	// �� ������ ��� ���ؼ��� int�� �ƴ� long long�� ����Ѵ�.

	int t; cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n; cin >> n;
		std::vector<int> stockArr(n + 1);

		// �� �� �ֽ� �Է�
		for (int j = 1; j <= n; ++j)
			cin >> stockArr[j];

		long long result = 0;
		int maxPrice = stockArr[n];

		/// �ְ� �ְ� �������� �ڿ������� ������ �Ѵ� (�ֽ��� ���� ���� ���� �Ǻ��� �����ϴ�)
		for (int j = n - 1; j >= 1; --j)
		{
			if (maxPrice < stockArr[j])
				maxPrice = stockArr[j];
			else
				result += maxPrice - stockArr[j];
		}

		cout << result << endl;
	}

	return 0;
}