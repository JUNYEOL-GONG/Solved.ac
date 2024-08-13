#include <bits/stdc++.h>
using namespace std;

int n, w, L;
queue<int> a;
deque<pair<int, int>> b;		// deque�� �ε����� ������ �� �ִ�

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : Ʈ��

	cin >> n >> w >> L;
	for (int i = 0; i < n; ++i) {
		int weight; cin >> weight;
		a.push(weight);
	}

	int time = 0;
	int sum = 0;

	while (true) {

		if (a.empty() && b.empty())
			break;

		// 1�� ���
		time++;

		// �ٸ� ���� �ö� �ִ� Ʈ������ �� ĭ�� �̵���Ų��
		for (int i = 0; i < b.size(); ++i) {
			b[i].second++;
		}

		// �ٸ��� ������ ������ Ʈ������ �ٸ����� �����Ѵ�
		while (!b.empty() && b.front().second > w) {
			sum -= b.front().first;
			b.erase(b.begin());
		}

		if (a.empty()) continue;				// ���̻� Ʈ���� �������� ���� ��� ��ŵ
		if (sum + a.front() > L) continue;		// Ʈ���� ����������, ������ ���̻� �� ��Ƽ�� ��� ��ŵ
		if (b.size() + 1 > w) continue;			// Ʈ���� ����������, �ٸ��� ���� ��� ��ŵ

		// �ٸ� ���� �Լ��Ѵ�
		sum += a.front();
		b.push_back({ a.front(), 1 });
		a.pop();
	}

	cout << time;

	return 0;
}
