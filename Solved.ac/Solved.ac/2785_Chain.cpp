#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ü��

	/*
	 * N : ü���� ����
	 */

	int N; cin >> N;

	std::vector<int> lengthArr(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		cin >> lengthArr[i];
	}

	/// �׸��� �˰����� �ٽ��� �Ǵ� ����Ʈ 1 - ü���� ���� �Ҹ��Ű�� ������� ������ �ٱ� ������ �������� ������ ���.
	///	'�Է� �迭�� ������ �߿����� �Ǵ�'
	std::sort(lengthArr.begin(), lengthArr.end());

	/// �׸��� �˰����� �ٽ��� �Ǵ� ����Ʈ 2 - �ʿ��� ������� ������ ������ ü���� ������ �̿��� ������ �ذ��Ѵ�.
	///	�پ��� ���ܰ� ������ �Ͱ��� ���� ������ ������ �ڿ������� �� �������� �ذ�Ǵ� '�ܼ�ȭ' ������ ���� ���� �ذ�
	int needGoriCnt = N - 1;
	int totalGoriCnt = 0;

	for (int i = 1; i <= N; ++i)
	{
		int curChainCnt = lengthArr[i];

		// ü���� ���̸�ŭ ����
		for (int j = 0; j < lengthArr[i]; ++j)
		{
			if (needGoriCnt == totalGoriCnt)
				break;

			// ü���� ���� �����.
			curChainCnt--;
			totalGoriCnt++;

			// ü���� ���� ������ ��ü�� ���
			if (curChainCnt <= 0)
			{
				needGoriCnt--;
				break;
			}
		}


		if (needGoriCnt <= totalGoriCnt)
			break;
	}

	cout << totalGoriCnt << endl;

	return 0;
}