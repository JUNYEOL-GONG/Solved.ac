#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ���� ��ȣ ���̱�

	int N; cin >> N;

	std::vector<std::vector<char>> map(N + 1);
	for (auto& vec : map)
		vec.resize(N + 1);

	// Map ����
	for (int i = 1; i <= N; ++i)
	{
		string input; cin >> input;

		for (int j = 1; j <= N; ++j)
		{
			map[i][j] = input[j - 1];
		}
	}

	// 1. n x n�� Map�� (1,1)���� (n,n)���� ��ȸ�Ѵ�.
	// 2. ��ȸ �ϸ鼭 1�� ã�� ���� ����Ʈ ������ ���Ѵ�
	// 3. ���̻� ������ ���ٸ� ��� �湮ó���� �Ͽ� �� ����Ʈ ������ ������ �Ѵ�
	// 4. ��ȸ�� �������� �ٽ� (1)�� �������� ������Ѵ�.
	// 5. �׷��� ������ ��, ������ ���� ���� ���Ѵ� (�������� ����)



	return 0;
}