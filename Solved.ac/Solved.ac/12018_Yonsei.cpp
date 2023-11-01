#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Descending(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// TOTO

	/*
	 * n : ���� �� (1 <= n <= 100)
	 * m : �־��� ���ϸ��� (1 <= m <= 100)
	 * pArr : �� ���� ��û�� ����� ���� ���� �迭
	 * lArr : �� ������ ���� �ο�
	 * mArr : �� ����� ���ϸ����� �󸶳� �־�����
	 */

	int n; cin >> n;
	int m; cin >> m;

	std::vector<int> pArr(n + 1);
	std::vector<int> lArr(n + 1);

	std::vector<vector<int>> mArr(n + 1);
	std::vector<int> bestChoiceArr(n + 1);

	size_t cnt = 0;

	for (int i = 1; i <= n; ++i)
	{
		cin >> pArr[i];
		cin >> lArr[i];

		mArr[i].resize(pArr[i] + 1);
		for (int j = 1; j <= pArr[i]; ++j)
		{
			cin >> mArr[i][j];
		}

		// ����� ���ϸ��� �������� ����
		std::sort(mArr[i].begin() + 1, mArr[i].end(), Descending);
	}

	// ������û ������ �߿��� ��Ȳ
	// ���ݰ� ���°� ���� ���ݾ�? like me?

	for (int i = 1; i <= n; ++i)
	{
		/// ��û�� �ο��� (pArr) �� ���� ���� �ο��� (lArr) ���� ������ �׳� 1�� ���ϸ��� �־ ��û�� �����ϴ�.

		if (pArr[i] < lArr[i])
			bestChoiceArr[i] = 1;
		else
			bestChoiceArr[i] = mArr[i][lArr[i]];
	}

	// �������� ����
	sort(bestChoiceArr.begin() + 1, bestChoiceArr.end());

	for(auto it = bestChoiceArr.begin() + 1; it != bestChoiceArr.end(); ++it)
	{
		m -= *it;

		if (m < 0)
			break;

		cnt++;
	}

	cout << cnt << endl;

	return 0;
}