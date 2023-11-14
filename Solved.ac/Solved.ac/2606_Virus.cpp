#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ��ȣ ���� ��� �ڷᱸ���� ���� ���ΰ�?
std::vector<std::vector<int>> vec;

// ���̷��� �ɸ� ��ǻ��
std::vector<int> virusComputer;

/// <summary>
/// DFS�� ���� Ž�� ���ִ� �Լ�
/// </summary>
/// <param name="n"></param>
void DFS(int n)
{
	// ���� �� n�� virusComputer���� ã�´�.
	auto it = std::find(virusComputer.begin(), virusComputer.end(), n);

	// ���� ������ ����
	if (it != virusComputer.end())
		return;
	// ���� ������ �߰�
	else
		virusComputer.push_back(n);

	// ������ ���� ���� '���� �켱 Ž��'
	for (size_t i = 0; i < vec[n].size(); ++i)
	{
		DFS(vec[n][i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ���̷���

	/*
	 * computerCount : ��ǻ���� ��
	 * network : ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ��ǻ�� ���� ��
	 */

	int computerCount; cin >> computerCount;
	int networkCount; cin >> networkCount;

	vec.resize(computerCount + 1);

	// ������ �׷���
	for (int i = 0; i < networkCount; ++i)
	{
		int from; cin >> from;
		int to; cin >> to;

		vec[from].push_back(to);
		vec[to].push_back(from);
	}

	// 1�� ��ǻ�Ͱ� �� ���̷����� �ɷ��� ��, 1�� ��ǻ�͸� ���� �� ���̷����� �ɸ��� �Ǵ� ��ǻ���� ���� ù° �ٿ� ����Ѵ�.
	DFS(1);

	// ��Ʈ ��ǻ�� 1���� ������ ���̷��� �ɸ� ��
	cout << virusComputer.size() - 1 << endl;


	return 0;
}