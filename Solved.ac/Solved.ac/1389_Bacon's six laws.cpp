#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

std::vector<std::vector<int>> vecArr;
std::vector<bool> visited;

void ResetVisited()
{
	for (int i = 0; i < visited.size(); ++i)
		visited[i] = false;
}

// user���� target���� �ּ� connect count ���ϱ�
int GetMinConnectEachPerson(int start, int target)
{
	int count = 0;

	// �� ���������� �ٽ� ����Ʈ : Queue�� (��� ��ȣ)�� (���Ŀ� Ƚ��)�� �Բ� ������ �ֵ��� �Ѵ�.
	std::queue<std::pair<int, int>> myQueue;
	myQueue.push(std::make_pair(start, 0));
	visited[start] = true;

	while (!myQueue.empty())
	{
		const auto fromInfo = myQueue.front();
		myQueue.pop();

		// ģ�� �߿� Ÿ���� �ִٸ� �׶��� ���Ŀ� Ƚ���� ������ �����Ѵ�.
		if (fromInfo.first == target)
		{
			count = fromInfo.second;
			break;
		}

		for (int i = 0; i < vecArr[fromInfo.first].size(); ++i)
		{
			int myFriend = vecArr[fromInfo.first][i];

			if (!visited[myFriend])
			{
				myQueue.push(std::make_pair(myFriend, fromInfo.second + 1));
				visited[myFriend] = true;
			}
		}
	}

	return count;
}

// �ش� ������ ������ �ѹ��� �˾Ƴ��� �Լ�
int GetKevinBaconNumber(int user)
{
	int kevinBaconNumber = 0;

	for (int target = 1; target <= vecArr.size(); ++target)
	{
		if (user == target)
			continue;

		kevinBaconNumber += GetMinConnectEachPerson(user, target);
		ResetVisited();
	}

	return kevinBaconNumber;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// �ɺ� ������ ����

	int N; cin >> N;
	int M; cin >> M;

	vecArr.resize(N + 1);
	visited.resize(N + 1);

	while (M-- > 0)
	{
		int from; cin >> from;
		int to; cin >> to;

		if (from == to)
			continue;

		vecArr[from].push_back(to);
		vecArr[to].push_back(from);
	}

	int minKevin = 9999999999;
	int personNumber = 0;

	for (int user = 1; user <= N; ++user)
	{
		int kevinBaconNumber = GetKevinBaconNumber(user);
		if (minKevin > kevinBaconNumber)
		{
			minKevin = kevinBaconNumber;
			personNumber = user;
		}
	}

	cout << personNumber << '\n';

	return 0;
}
