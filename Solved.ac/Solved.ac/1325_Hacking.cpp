#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

// ���� ����Ʈ ���
std::vector<std::vector<int>> reverseTrustList;

// �湮 ����
bool visited[10001] = {};

// ��ŷ ���� Ƚ��
int hackingCount = 0;

// second(��ŷ Ƚ��)�� ū �������, first(��ǻ�� ��ȣ)�� ���� �������
bool compare(std::pair<int, int> a, std::pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;

	return a.second > b.second;
}

void ResetVisited()
{
	for(int i=0; i<10001; ++i)
		visited[i] = false;
}

void DFS(int parentNumber)
{
	// targetNumber�� �湮ó��
	visited[parentNumber] = true;

	// �ڽ��� �ŷ��ϴ� ��� ��ǻ�͸� "���ÿ�" ��ŷ�� �� �ִ�.
	hackingCount++;

	// �ڽ��� �ŷ��ϴ� ��� ��ǻ�͸� ��� ��ȸ
	for (int i = 0; i < reverseTrustList[parentNumber].size(); ++i)
	{
		int targetNumber = reverseTrustList[parentNumber][i];

		if (!visited[targetNumber])
			DFS(targetNumber);
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ȿ������ ��ŷ

	/*
	 * N : ��ǻ�� ��ȣ ����
	 * M : �ŷ� ����
	 */

	/// ó���� ������ �߸� �����ߴ�.
	///	�ڽ��� �ŷ��ϴ� ��ǻ�� �� �ϳ��� ��ŷ�� �� �ִٰ� ������ ���� ��
	///	�ڽ��� �ŷ��ϴ� ��� ��ǻ�͸� ���ÿ� ��ŷ�� �� �־���.

	int N, M;
	cin >> N >> M;

	// ��������� �뷮 �ʰ��� ��� �Ұ�
	// int reverseTrustList[10001][10001];

	reverseTrustList.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int from, to;
		cin >> from >> to;

		reverseTrustList[to].push_back(from);
	}

	// �ִ� ��ŷ ������ ��ǻ�� �迭
	std::vector<std::pair<int, int>> computerArr;

	for (int i = 1; i <= N; ++i)
	{
		// i�� ��ǻ�͸� ��ŷ
		DFS(i);

		// �湮 ���� �ʱ�ȭ
		ResetVisited();

		// i�� ��ǻ�Ϳ� �ش� ��ǻ�Ϳ� ���� ��ŷ ī��Ʈ�� �迭�� �߰�
		computerArr.emplace_back(i, hackingCount);

		hackingCount = 0;
	}

	std::sort(computerArr.begin(), computerArr.end(), compare);

	int maxHackingCount = computerArr[0].second;

	for (const auto v : computerArr)
	{
		if (v.second != maxHackingCount)
			break;

		cout << v.first << " ";
	}

	return 0;
}
