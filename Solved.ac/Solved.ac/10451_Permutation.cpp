#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �ϳ� �ϳ� Ÿ�� ����.
void DFS(int node, std::vector<int>& numberArr, std::vector<int>& alreadyDone)
{
	auto it = std::find(alreadyDone.begin(), alreadyDone.end(), node);

	// �ϳ��� ����Ŭ ����
	if (it != alreadyDone.end())
		return;
	else
		alreadyDone.push_back(node);

	DFS(numberArr[node], numberArr, alreadyDone);
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
	for (int i = 0; i < T; ++i)
	{
		int N; cin >> N;

		int cnt = 0;

		std::vector<int> numberArr(N + 1);
		std::vector<int> already_done;

		// ���� �׷��� ����
		for (int j = 1; j <= N; ++j)
		{
			int value; cin >> value;
			numberArr[j] = value;
		}

		// ���� ���� ���� ����Ŭ�� ����.
		for (int j = 1; j <= N; ++j)
		{
			auto it = std::find(already_done.begin(), already_done.end(), j);
			if (it != already_done.end())
				continue;
			else
			{
				// �ϳ� �ϳ� Ÿ�� ����
				DFS(j, numberArr, already_done);
				cnt++;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}