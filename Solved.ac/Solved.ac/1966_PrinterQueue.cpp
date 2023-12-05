#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ������ ť

	int T; cin >> T;

	while (T-- > 0)
	{
		// N : ������ ����
		// M : ���� �����ִ��� �ñ��� ��ġ (0�� �� ����)
		int N, M;
		cin >> N >> M;

		std::queue<std::pair<int, int>> myQueue;

		for (int i = 0; i < N; ++i)
		{
			// 1 ~ 9�� �߿䵵
			int priority; cin >> priority;
			myQueue.emplace(i, priority);
		}

		int order = 0;

		while (!myQueue.empty())
		{
			std::queue<std::pair<int, int>> tempQueue = myQueue;

			auto myElement = myQueue.front();

			// �켱������ ���� ���Ƽ� �׳� �� �� �ֵ� �ڷ� �Ѱ����ϵ� �켱 Pop�� �Ѵ�
			myQueue.pop();

			// �ڷ� ������ ����
			bool isPush = false;

			// �ڿ� ������ �߿䵵�� ���� ������ �ִ��� Ȯ���ϱ�
			while (!tempQueue.empty())
			{
				// ������ �켱���� ���� ���
				if (myElement.second < tempQueue.front().second)
				{
					// �ڷ� �ٽ� �ִ´�.
					isPush = true;
					break;
				}
				// ���� ��ҿ� �񱳸� ���� Pop
				else
					tempQueue.pop();
			}

			if (isPush)
				myQueue.push(myElement);
			else
			{
				order++;

				if (myElement.first == M)
				{
					cout << order << '\n';
					break;
				}
			}
		}
	}


	return 0;
}
