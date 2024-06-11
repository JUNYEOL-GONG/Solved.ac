#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;

// ����� ����
int N;

// ���� ����Ʈ ������� Ʈ���� ���踦 ����
std::vector<std::vector<int>> tree(100001);

// ����� ������ ���� �湮ó��
bool visited_J[100001] = {};

// �θ� ��带 ���� (index : �ڽ� ��ȣ, value : �θ� ��ȣ)
std::vector<int> parentArr(100001);

// DFS�� ���� Ž���̹Ƿ� ���� ����Ʈ�� ��� ��� ������ ��ȸ�Ѵ�.
void DFS(int parentNode)
{
	// ���� "�θ� ���"�� �������� �����Ѵ�.
	// �湮 ó��
	visited_J[parentNode] = true;

	// �θ� ����� ��� �ڽĵ��� ��ȸ�ϸ�, �ڽĵ��� �θ� ����
	for (int i = 0; i < tree[parentNode].size(); ++i)
	{
		// �θ� ��忡 ����� "�ڽ� ���"
		int childNode = tree[parentNode][i];

		// * �湮 ������ �˻��ϴ� ������ �ڽ� ��常 �������� ���� *
		if (!visited_J[childNode])
		{
			// ���� �켱 Ž���� ���� "��� �Լ�"�� �����Ѵ�. (�ش� ��带 �θ� ���� �Է���)
			DFS(childNode);

			// �ڽ� ��忡 �θ� ������ ���
			parentArr[childNode] = parentNode;
		}
	}
}

// BFS�� ���� Ž���̹Ƿ� ���� ����Ʈ�� ��� ��� ������ ��ȸ�Ѵ�.
void BFS(int rootNode)
{
	// �ʺ� �켱 Ž���� ���� "Queue �ڷᱸ��"�� ����Ѵ�
	std::queue<int> myQueue;
	// ó�� ���� ����� ��Ʈ ��带 �湮 ó��
	visited_J[rootNode] = true;
	// ��Ʈ ��带 ó���� Queue�� ��� ����
	myQueue.push(rootNode);

	// Queue�� ��尡 ������ ����ؼ� �ݺ�
	while (!myQueue.empty())
	{
		// Queue�� ���� �տ� �ִ� ���, �� ���� ���� ���� ��带 ������. (�θ� ���)
		int parentNode = myQueue.front();
		// ���� ��带 parentNode�� �����߱� ������ Pop()�Ѵ�.
		myQueue.pop();

		// �θ� ����� ��� �ڽĵ��� ��ȸ�ϸ�, �ڽĵ��� �θ� ����
		for (int i = 0; i < tree[parentNode].size(); ++i)
		{
			// �θ� ��忡 ����� "�ڽ� ���"
			int childNode = tree[parentNode][i];

			// * �湮 ������ �˻��ϴ� ������ �ڽ� ��常 �������� ���� *
			if (!visited_J[childNode])
			{
				// Queue�� �ڽ� ��带 Push()���ش�.
				myQueue.push(childNode);

				visited_J[childNode] = true;

				// �ڽ� ��忡 �θ� ������ ���
				parentArr[childNode] = parentNode;
			}
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

	// ���� ������ �־�����.
	for (int i = 0; i < N - 1; ++i)
	{
		int from, to;
		cin >> from >> to;

		tree[from].push_back(to);
		tree[to].push_back(from);
	}

	/// ��Ʈ ��忡������ ��� ��带 Ž���Ѵ�.

	// DFS(1);
	BFS(1);

	// ù° �ٺ��� N-1���� �ٿ� �� ����� �θ� ��� ��ȣ�� 2�� ������ ������� ����Ѵ�.
	for (int i = 2; i <= N; ++i)
		cout << parentArr[i] << '\n';

	return 0;
}
