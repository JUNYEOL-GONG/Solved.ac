#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

// ���� ����Ʈ ���
std::vector<std::vector<int>> reverseTrustList;

// �湮 ����
bool visited[10001] = {};

// ��ŷ ���� Ƚ��
int hackingCount = 0;

// �ִ� ��ŷ ���� Ƚ��
int maxHackingCount = 0;

void DFS(int startNumber, int curNumber)
{
	// �ڽ��� �ŷ��ϴ� ��� ��ǻ�͸� "���ÿ�" ��ŷ�� �� �ִ�.
	hackingCount++;

	// �ڽ��� �ŷ��ϴ� ��� ��ǻ�͸� ��� ��ȸ
	for (int i = 0; i < reverseTrustList[curNumber].size(); ++i)
	{
		int targetNumber = reverseTrustList[curNumber][i];

		if (!visited[targetNumber])
		{
			visited[targetNumber] = true;
			DFS(startNumber, targetNumber);
			visited[targetNumber] = false;
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ȿ������ ��ŷ

	/*
	 * N : ��ǻ�� ��ȣ ����
	 * M : �ŷ� ����
	 */

	/// ó���� ������ �߸� �����ߴ�.
	///	�ڽ��� �ŷ��ϴ� ��ǻ�� �� �ϳ��� ��ŷ�� �� �ִٰ� ������ ���� ��
	///	�ڽ��� �ŷ��ϴ� ��� ��ǻ�͸� ���ÿ� ��ŷ�� �� �־���.

	int N, M;
	cin >> N >> M;

	// ��������� �뷮 �ʰ��� ��� �Ұ�
	// int reverseTrustList[10001][10001];

	reverseTrustList.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int from, to;
		cin >> from >> to;

		reverseTrustList[to].push_back(from);
	}

	// �ִ� ��ŷ ������ ��ǻ�� �迭
	std::vector<int> computerArr;

	for (int i = 1; i <= N; ++i)
	{
		if (reverseTrustList[i].empty())
			continue;

		visited[i] = true;
		DFS(i, i);
		visited[i] = false;

		if(maxHackingCount <= hackingCount)
		{
			maxHackingCount = hackingCount;
			computerArr.emplace_back(i);
		}

		hackingCount = 0;
	}

	std::sort(computerArr.begin(), computerArr.end());

	for (const auto v : computerArr)
		cout << v << " ";

	return 0;
}
