#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[1001];
bool alreadyDone[1001];

void dfs(int node)
{
	// �̹� Ž�� ������
	if(!alreadyDone[node])
	{
		alreadyDone[node] = true;

		int nextNode = graph[node];
		dfs(nextNode);
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ���� ����Ŭ ���� ���ϱ�

	/*
	 * T : �׽�Ʈ ���̽� ����
	 * N : ������ ũ��
	 */

	int T; cin >> T;

	// �׽�Ʈ ���̽�
	while (T > 0)
	{
		T--;

		// �ʱ�ȭ
		for (int i = 1; i <= 1000; ++i)
			graph[i] = 0;
		for (int i = 1; i <= 1000; ++i)
			alreadyDone[i] = false;

		// ��� ����
		int N; cin >> N;

		// ���� �׷��� ����
		for (int i = 1; i <= N; ++i)
			cin >> graph[i];

		int cycleCnt = 0;

		// ������ ����Ŭ�� Ȯ��
		for (int i = 1; i <= N; ++i)
		{
			// ���� ������ ���� ���� �� �ش� ����Ŭ�� Ž���Ѵ�.
			if (alreadyDone[i] == false)
			{
				dfs(i);
				cycleCnt++;
			}
		}

		cout << cycleCnt << endl;
	}
}