#include <iostream>
#include <algorithm>

using namespace std;

int N;
int graph[11][11];
bool visited[11];

int minCost = 1000000 * 10 + 1;

void BFS(int startNode, int curNode, int remainCnt, int curCost)
{
	// �� ���� ���ư��� �ϸ� ������ ��
	if (remainCnt == 0)
	{
		// ���������� ���ư��� ��� ���ϱ�
		if (graph[curNode][startNode] != 0)
			minCost = std::min(curCost + graph[curNode][startNode], minCost);

		return;
	}

	// startNode���� cnt���� ��带 Ž���ϰ�, �ּ� ����� ���Ѵ�.
	for (int nextNode = 1; nextNode <= N; ++nextNode)
	{
		// �� �� �ִ� ���̰�, �湮������ ���� ���
		if (graph[curNode][nextNode] != 0 && visited[nextNode] == false && curCost < minCost)
		{
			visited[nextNode] = true; // �湮ó��.

			BFS(startNode, nextNode, remainCnt - 1, curCost + graph[curNode][nextNode]);

			visited[nextNode] = false; // ������ ���� �������Ƿ�, �湮ó���� öȸ�Ѵ�.
		}
		else
			continue;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ���ǿ� ��ȸ 2

	cin >> N;

	// �׷��� ����
	// index 0�� �����ϰ� �����Ѵ�.
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int cost; cin >> cost;
			graph[i][j] = cost;
		}
	}

	// ���� ���� ������� ��ȸ ���� �ϴ¹�
	// �� ���ÿ��� N���� ��� ���ø� ���� �ٽ� ������ ���÷� ���ƿ��� ���

	// 1. ��� ���ÿ��� �������
	// 2. � ��η� ��ȸ����

	// �� �ΰ��� ��� ����ؼ� ��ȸ�ϰ�, �� �� �ִ� ��θ� ã�ƾ� �Ѵ�.

	int finalMinCost = 1000000 * 10 + 1;
	for (int i = 1; i <= N; ++i)
	{
		visited[i] = true;

		BFS(i, i, N - 1, 0);

		// �湮���� �ʱ�ȭ
		// std::memset(visited, false, sizeof(visited));
		std::fill(std::begin(visited), std::end(visited), false);

		// ���� �ּ� ��� ���
		finalMinCost = std::min(finalMinCost, minCost);
	}

	cout << finalMinCost << endl;

	return 0;
}