#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int w[11][11];
bool v[11];

int minCost = 1000000 * 10;

void BFS(int start)
{
	// �� �������� ��� ��θ� �� ���鼭 �ִ� ��θ� Ž���Ѵ�.
	std::queue<int> myQueue;

	// ���� ������ Queue�� �ְ� ����
	myQueue.push(start);
	v[start] = true;

	// Queue�� �ƹ� ���� ���� ���������� �ݺ� ����
	while (!myQueue.empty())
	{
		// �ش� �������� �̾��� ��� ��θ� �ϳ��ϳ� Ž��
		for (int i = 1; i <= N; ++i)
		{
			// �湮���� ���� �����̶��
			if (v[i] == false && w[myQueue.front()][i] != 0)
			{
				// Queue�� �ְ�
				myQueue.push(i);

				// ��� ����� �����Ѵ�.
				// myQueue.front()
			}
		}

		myQueue.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ���ǿ� ��ȸ 2

	cin >> N;

	// ��� �׷��� ����
	// index 0�� �����ϰ� �����Ѵ�.
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int cost; cin >> cost;

			w[i][j] = cost;
		}
	}

	// ���� ���� ������� ��ȸ ���� �ϴ¹�
	// �� ���ÿ��� N���� ��� ���ø� ���� �ٽ� ������ ���÷� ���ƿ��� ���

	// 1. ��� ���ÿ��� �������
	// 2. � ��η� ��ȸ����

	// �� �ΰ��� ��� ����ؼ� ��ȸ�ϰ�, �� �� �ִ� ��θ� ã�ƾ� �Ѵ�.

	// 1)
	for (int i = 1; i <= N; ++i)
	{
		// 2)
		BFS(i);
	}


	for (int i = 1; i <= N; ++i)
	{
		cout << i << " : ";
		for (int j = 1; j <= N; ++j)
		{
			cout << w[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}