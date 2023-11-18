#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ����

	int N; cin >> N;
	int M; cin >> M;

	std::vector<int> cardNumArr(N);

	for (int i = 0; i < N; ++i)
	{
		int value; cin >> value;
		cardNumArr[i] = value;
	}

	// std::sort(cardNumArr.begin(), cardNumArr.end(), compare);

	int finalSum = 0;

	// M���� ���Ұǵ�
	// ��� ���Ұ���?

	for (int i = 0; i < N; ++i)
	{
		int part1 = cardNumArr[i];

		for (int j = 0; j < N; ++j)
		{
			if (i == j)
				continue;

			int part2 = cardNumArr[j];

			for (int k = 0; k < N; ++k)
			{
				if (i == k || j == k)
					continue;

				int part3 = cardNumArr[k];

				int partSum = part1 + part2 + part3;

				if (partSum <= M)
				{
					finalSum = std::max(partSum, finalSum);
				}
			}
		}
	}

	cout << finalSum << endl;

	return 0;
}