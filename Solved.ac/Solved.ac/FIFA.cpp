#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define POSITION_COUNT 11

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// N : ������ ��
	// K : after year
	int N, K;
	cin >> N >> K;

	// 0�� �ε����� ������� ����
	vector<vector<size_t>> players(POSITION_COUNT + 1);

	// 0. ���� �� 11������, ������ ��ȣ�� 1�̻� 11������ �����̴�.
	for (size_t i = 0; i < N; ++i)
	{
		int P, W;
		cin >> P >> W;

		players[P].push_back(W);
	}

	// 1. ������ ���� ���� ��ġ�� ���� �������� ����
	for (size_t i = 1; i <= POSITION_COUNT; ++i)
	{
		sort(players[i].begin(), players[i].end(), greater<size_t>());
	}

	while (K > 0)
	{
		// 2. 3���� �����Ǻ� ���� ��ġ�� ���� ���� ������ ����
		for (size_t i = 1; i <= POSITION_COUNT; ++i)
		{
			if (!players[i].empty())
			{
				// 3. 8���� ���� ������ ���� ��ġ�� -1 (>= 0)
				if (players[i][0] > 0)
				{
					players[i][0]--;

					// 4. 11���� 2�� �������� �籸��
					for (size_t j = 1; j < players[i].size(); ++j)
					{
						if (players[i][j] < players[i][0])
						{
							swap(players[i][0], players[i][j - 1]);
							break;
						}
					}
				}
			}
		}

		K--;
	}

	size_t teamWorth = 0;

	for (size_t i = 1; i <= POSITION_COUNT; ++i)
	{
		if (!players[i].empty())
		{
			teamWorth += players[i][0];
		}
	}

	cout << teamWorth << '\n';

	return 0;
}