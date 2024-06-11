#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;

int visited_J[26][26];

int deltaCol[4] = { 0, 0, -1, 1 };
int deltaRow[4] = { -1, 1, 0,0 };

struct Position
{
	int x, y;

	Position(int _x, int _y)
		: x(_x), y(_y)
	{}
};

int SearchAptBlock_BFS(std::vector<std::vector<char>>& map, Position pos)
{
	std::queue<Position> myQueue;
	visited_J[pos.y][pos.x] = true;
	myQueue.push(pos);
	int aptCnt = 1;

	while (!myQueue.empty())
	{
		// �����¿� ������� Ž��
		for (int k = 0; k < 4; ++k)
		{
			Position nextPos(myQueue.front().x + deltaCol[k], myQueue.front().y + deltaRow[k]);

			if (nextPos.x > N || nextPos.y > N || nextPos.x < 1 || nextPos.y < 1)
				continue;

			if (map[nextPos.y][nextPos.x] == '1' && visited_J[nextPos.y][nextPos.x] == false)
			{
				visited_J[nextPos.y][nextPos.x] = true;
				myQueue.push(nextPos);
				aptCnt++;
			}
		}

		myQueue.pop();
	}

	return aptCnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ���� ��ȣ ���̱�

	cin >> N;

	std::vector<std::vector<char>> map(N + 1);
	for (auto& vec : map)
		vec.resize(N + 1);

	// Map ����
	for (int i = 1; i <= N; ++i)
	{
		string input; cin >> input;

		for (int j = 1; j <= N; ++j)
		{
			map[i][j] = input[j - 1];
		}
	}

	// 1. n x n�� Map�� (1,1)���� (n,n)���� ��ȸ�Ѵ�.
	// 2. ��ȸ �ϸ鼭 1�� ã�� ���� ����Ʈ ������ ���Ѵ�
	// 3. ���̻� ������ ���ٸ� ��� �湮ó���� �Ͽ� �� ����Ʈ ������ ������ �Ѵ�
	// 4. ��ȸ�� �������� �ٽ� (1)�� �������� ������Ѵ�.
	// 5. �׷��� ������ ��, ������ ���� ���� ���Ѵ� (�������� ����)

	int aptBlockCnt = 0;
	std::vector<int> aptCntArr;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			// ����Ʈ ���� ã��
			if (map[i][j] == '1' && visited_J[i][j] == false)
			{
				aptBlockCnt++;

				const Position searchPos(j, i);

				// ������ Ž��
				int aptCnt = SearchAptBlock_BFS(map, searchPos);

				// ���� �� ����Ʈ�� ����
				aptCntArr.push_back(aptCnt);
			}
		}
	}

	// ���� �� ����Ʈ�� ������ ����
	std::sort(aptCntArr.begin(), aptCntArr.end());

	cout << aptBlockCnt << endl;
	for (const auto& v : aptCntArr)
		cout << v << endl;

	return 0;
}