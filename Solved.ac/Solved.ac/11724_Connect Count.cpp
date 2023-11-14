#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ������ �׷����� 2���� �迭�� ��ƾ� �Ѵ�.
std::vector<std::vector<int>> graphs;

// �湮ó���� ���� ���� ����
bool visited[1001] = { false, };

void DFS(int node)
{
	if (visited[node] == false)
	{
		// �湮 ó��
		visited[node] = true;

		for (int i = 0; i < graphs[node].size(); ++i)
		{
			DFS(graphs[node][i]);
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ���� ����� ����

	int N; cin >> N;
	int M; cin >> M;

	// ���� ����� ������ ��� ���� ����
	int cnt = 0;

	graphs.resize(N + 1);

	// ������ �׷��� ����
	for (int i = 0; i < M; ++i)
	{
		int u; cin >> u;
		int v; cin >> v;

		graphs[u].push_back(v);
		graphs[v].push_back(u);
	}

	// ��ȯ�ϴ� ����Ŭ�� ���� (���� ���) ���ϱ�
	for (int i = 1; i <= N; ++i)
	{
		// �湮���� �ʾ����� Ž��
		if (visited[i] == false)
		{
			// �� ���� ��ҿ� ���� Ž��
			DFS(i);

			// �ش� ���� ����� Ž���� ����Ǹ� ���� ��� ī��Ʈ ����
			cnt++;
		}
		// �湮������ ���� ���� ��Ҹ� ã��
		else
			continue;
	}

	cout << cnt << endl;

	/*
	 * 2���� ������ ��Ҹ� ����ϴ� �ڵ�
	for (int i = 1; i <= N; ++i)
	{
		cout << "index " << i << " : ";

		for (int j = 0; j < graphs[i].size(); ++j)
		{
			cout << graphs[i][j] << " ";
		}

		cout << endl;
	}
	*/

	return 0;
}