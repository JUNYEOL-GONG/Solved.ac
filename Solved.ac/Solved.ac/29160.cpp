#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define POSITION_COUNT 11

struct PlayerByPos
{
	int number;
	int worth;

	PlayerByPos() = default;
	PlayerByPos(int n, int w)
		: number(n), worth(w)
	{}
};

bool MaxWorth(const PlayerByPos& a, const PlayerByPos& b)
{
	if (a.worth < b.worth)
		return true;

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// N : ������ ��
	// K : after year
	int N, K;
	cin >> N >> K;

	vector<vector<PlayerByPos>> playersByPos(POSITION_COUNT);

	int teamWorth = 0;

	// 0. ���� �� 11������, ������ ��ȣ�� 1�̻� 11������ �����̴�.
	for (int playerNum = 1; playerNum <= N; ++playerNum)
	{
		int p, w;
		cin >> p >> w;

		playersByPos[p - 1].push_back(PlayerByPos(playerNum, w));
	}

	bool isOverNov = false;
	bool isOverAug = false;
	bool isOverK = false;

	// K���� ���
	while (K > 0)
	{
		// 1. 3���� �����Ǻ� ���� ��ġ�� ���� ���� ������ ����
		for (int positionNum = 0; positionNum < POSITION_COUNT; ++positionNum)
		{
			// 2. �����ǿ� �ش��ϴ� ������ ���� ��, �ش� �������� �������� ���� ����
			if (!playersByPos[positionNum].empty())
			{
				// ���� ��ġ�� ���� ���� ���� ����
				auto max_it = std::max_element(playersByPos[positionNum].begin(), playersByPos[positionNum].end(), MaxWorth);

				// ��ġ�� ���� ���� ������ ��ȣ ���ϱ�
				if (max_it != playersByPos[positionNum].end())
				{
					auto index = std::distance(playersByPos[positionNum].begin(), max_it);

					// 3. 8���� ���� ������ ���� ��ġ�� -1 (>= 0)
					if (!isOverAug && !isOverNov && !isOverK)
					{
						if (playersByPos[positionNum][index].worth > 0)
							playersByPos[positionNum][index].worth--;
					}
					// 5. K�� 12���� ���� ��ġ �� ���
					else if (isOverAug && isOverNov && isOverK)
					{
						teamWorth += playersByPos[positionNum][index].worth;
					}
				}
			}
		}

		// 4. 11���� 1�� �������� �籸��
		if (!isOverNov)
		{
			// 8���� ����
			isOverAug = true;

			// 11���� ����
			isOverNov = true;

			// ������ ���� ��쿡
			if (K == 1)
				isOverK = true;

			continue;
		}

		isOverNov = false;
		isOverAug = false;

		K--;
	}

	cout << teamWorth << endl;

	return 0;
}