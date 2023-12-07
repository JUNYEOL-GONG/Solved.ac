#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

bool compare(std::pair<int, int> a, std::pair<int, int> b)
{
	if (a.first == b.first)
		return a.second > b.second;

	return a.first < b.first;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ����ũ����Ʈ

	// N x M x B = 500 x 500 x 256 = 64,000,500 (�� 6õ��)
	// 1�ʿ� �� 1��� ������ �����ϹǷ�, ���� ���� ��� ��츦 Ž���ϴ� "���Ʈ ����" �˰����� ����� �� �ִ�.

	int N, M, B;
	cin >> N >> M >> B;

	std::vector<std::vector<int>> height(N);
	for (auto& vec : height)
		vec.resize(M);

	// ���� ����
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int landHeight; cin >> landHeight;
			height[i][j] = landHeight;
		}
	}

	// ������ �����ϰ� ������

	const int rowCount = N;
	const int columnCount = M;

	int minElapsedTime = INT32_MAX;
	int resultHeight = 0;

	// 0������ 256������ ���鼭 �� �������� �ʿ��� �� ������ ���� �ּ��� ���� Ÿ�� ���̴�.
	for (int targetHeight = 0; targetHeight <= 256; ++targetHeight)
	{
		int elapsedTime = 0;
		int removeCount = 0;
		int addCount = 0;

		// �ش� ���� ���ؼ� �߰� / ���Ű� �ʿ��� ���� ���� ���
		for (int i = 0; i < rowCount; ++i)
		{
			for (int j = 0; j < columnCount; ++j)
			{
				// ���Ű� �ʿ���
				if (height[i][j] - targetHeight > 0)
					removeCount += height[i][j] - targetHeight;
				// �߰��� �ʿ���
				else
					addCount += targetHeight - height[i][j];
			}
		}

		// ���� �����ϸ� �ȵȴ�.
		if (addCount > removeCount + B)
			continue;

		// �ð� ��� ���
		// �̷��� �ѹ��� ���Ƽ� �ð��� ����� �� �ִ�.
		// * remove�� add �۾��� �ǽð����� ���� �ʾƵ� �ȴ�. �������� �ѹ��� *
		elapsedTime += removeCount * 2 + addCount * 1;

		// �ּ� ������� �Ǵ�
		if (minElapsedTime >= elapsedTime)
		{
			minElapsedTime = elapsedTime;
			resultHeight = targetHeight;
		}
	}

	cout << minElapsedTime << " " << resultHeight << '\n';

	return 0;
}
