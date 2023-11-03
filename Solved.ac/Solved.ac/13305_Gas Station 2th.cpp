#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ������ 2th try

	/*
	 * n : ������ ����
	 * lengthArr : �����Ұ� �Ÿ�
	 * priceArr : ���� ����
	 */

	///
	/// �������� �ִ� ���� : 100,000
	///	�����Ұ� �ִ� �Ÿ� : 1,000,000,000 -> ���� (�� �Ÿ�)
	///	���ʹ� ���� ���� : 1,000,000,000
	///
	///	-> �ִ� ���� ��� : 100,000 * 1,000,000,000 * 1,000,000,000 = 10^20 (�� ������ �� ����)
	///
	/// -> ���� �˾����� "���� ���� ���ú��� ���� ������ ���ñ����� �Ÿ��� 1�̻� 1,000,000,000 ������ �ڿ���."
	///	-> "���� ���� ���ú��� ���� ������ ���ñ����� �Ÿ�"
	///	-> �� ���ð� �Ÿ��� �ƴ϶� �� �Ÿ�����.
	///
	///	-> �ִ� ���� ��� : 100,000 (������ ����) * 100,000 (�����Ұ� �Ÿ�) * 1,000,000,000 (���� ����) = 10^15 (100�� ���� ����)
	///	-> long long���� ���� �� �ִ� �����̴�.
	///

	int n; cin >> n;

	std::vector<long long> lengthArr(n);
	std::vector<long long> priceArr(n + 1);

	// ������ ���� �Է�
	for (int i = 1; i <= n - 1; ++i)
		cin >> lengthArr[i];

	// ���� ���� �Է�
	for (int i = 1; i <= n; ++i)
		cin >> priceArr[i];

	long long totalMoney = 0;

	// ������ �����ұ����� �̵��ϸ� �Ǳ� ������ n - 1������ �ݺ����� ����.
	for (int i = 1; i < n; ++i)
	{
		const long long curPrice = priceArr[i];		// ���� �������� ������
		int passedCnt = 0;							// �׳� ����ĥ �������� ��


		/// ���õǴ� ������ �ִ�. (������ ������ �ϴ� ������ ���� �����Ұ� �����Ŀ� �����Ҹ� �ݿ��� ��ġ�̱� �����̴�)
		// ���� �����ҿ��� ���� �����ұ��� ����
		totalMoney += curPrice * lengthArr[i];

		// ����ĥ ������ ���
		for (int j = i + 1; j < n; ++j)
		{
			// ���� �����Ұ� ���� �����Һ��� ��θ� �̸� ������� �ʴ´�.
			if (curPrice > priceArr[j])
				break;

			// ���� �����Һ��� �ΰų� ������ ������ ���� �����ҿ��� �� ������ �̸� �Ѵ�.
			totalMoney += curPrice * lengthArr[j];
			passedCnt++;
		}

		i += passedCnt;
	}

	cout << totalMoney << endl;

	return 0;
}