#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int N;

// ���� ����Ʈ ���
std::vector<std::vector<int>> tree;

bool visited[100001] = {};

std::vector<int> parentArr;

void DFS(int parentNumber)
{
	visited[parentNumber] = true;

	for (int i = 0; i < tree[parentNumber].size(); ++i)
	{
		int child = tree[parentNumber][i];

		if (!visited[child])
		{
			DFS(child);
			parentArr[child] = parentNumber;
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : Ʈ���� �θ� ã��

	cin >> N;

	tree.resize(N + 1);
	parentArr.resize(N + 1);

	// ���� ������ �־�����.
	for (int i = 0; i < N - 1; ++i)
	{
		int from, to;
		cin >> from >> to;

		tree[from].push_back(to);
		tree[to].push_back(from);
	}

	/// ���ƴ�.. ��Ʈ ��忡�� �����ϸ� �Ǵ±���..
	DFS(1);

	// ù° �ٺ��� N-1���� �ٿ� �� ����� �θ� ��� ��ȣ�� 2�� ������ ������� ����Ѵ�.
	for (int i = 2; i < parentArr.size(); ++i)
		cout << parentArr[i] << '\n';

	return 0;
}
