#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<std::vector<int>> graphVec;
int visited[101];
int finalDepth = -1;

void DFS(int t1, int t2, int depth)
{
	if (t1 == t2)
	{
		finalDepth = depth;
		return;
	}

	for (int i = 0; i < graphVec[t1].size(); ++i)
	{
		if (visited[graphVec[t1][i]] == false)
		{
			visited[graphVec[t1][i]] = true;
			DFS(graphVec[t1][i], t2, depth + 1);
			visited[graphVec[t1][i]] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// �̼� ���

	/*
	 * ������ ������� ��ȣ�� �ο��ȴ�
	 * n : ��ü ����� ��
	 * t1, t2 : �̼��� ����� �� ���
	 * m : �θ� �ڽĵ� ���� ������ ����
	 * x : �θ� ��Ÿ���� ��ȣ
	 * y : x�� �ڽ��� ��Ÿ���� ��ȣ
	 */

	int n; cin >> n;

	graphVec.resize(n + 1);

	int t1; cin >> t1;
	int t2; cin >> t2;

	int m; cin >> m;

	while (m > 0)
	{
		m--;

		int x; cin >> x;
		int y; cin >> y;

		graphVec[x].push_back(y);
		graphVec[y].push_back(x);
	}

	// �̼� ���
	// t1�� t2�� ���� �θ� ã��
	// t1���� t2�� ã���� ���� �ִ� ��θ� ã�´�.
	int depth = 0;
	visited[t1] = true;
	DFS(t1, t2, depth);

	cout << finalDepth << endl;

	/*
	for (int i = 1; i < graphVec.size(); ++i)
	{
		cout << i << " : ";
		for (int j = 0; j < graphVec[i].size(); ++j)
		{
			cout << graphVec[i][j] << " ";
		}
		cout << endl;
	}
	*/

	return 0;
}