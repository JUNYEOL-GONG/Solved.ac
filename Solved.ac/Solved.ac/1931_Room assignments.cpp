#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b)
{
	// ���� �ð��� ���� ��, ���� �ð��� �� ���� ������� ���ĵǵ��� �Ѵ�.
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ȸ�ǽ� ����

	// ����
	// 1. �� ȸ�Ǵ� ��ġ�� �ʴ´�.
	// 2. ȸ�Ǵ� �����ϸ� �ߴ��� �Ұ��ϴ�.
	// 3. ȸ�ǰ� ������ ���ÿ� ���� ȸ�ǰ� ���۵� �� �ִ�.
	// 4. ȸ�� ���� �ð��� ���� �ð��� ���� �� �ִ�.

	// e.g) (1, 4) -> (4, 4) ����

	// ù° �ٿ� ȸ���� �� N(1 �� N �� 100,000)�� �־�����
	int n; cin >> n;
	int cnt = 0;
	int time = 0;
	vector<pair<int, int>> pairs(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> pairs[i].first;
		cin >> pairs[i].second;
	}

	// ȸ�� ���� �ð��� ���� ������� �����ϱ�
	std::sort(pairs.begin(), pairs.end(), Compare);

	// ù��° ȸ��
	time = pairs[0].second;
	cnt++;

	for (int i = 1; i < n; i++)
	{
		// ���� �ð��� ���� ȸ�� ���� �ð����� �۰ų� ������
		if (time <= pairs[i].first)
		{
			// �� ȸ�Ǹ� �� �� �ְ�, ���� �ð��� �����Ѵ�.
			time = pairs[i].second;
			cnt++;
		}
	}

	// �ִ� ����� �� �ִ� ȸ���� �ִ� ������ ���
	cout << cnt << endl;

	return 0;
}