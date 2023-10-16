#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ����Ʈ�� �����
	list<pair<int, string>> players;

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int age; string name;
		cin >> age >> name;

		players.push_back({ age, name });
	}

	stable_sort(players.begin(), players.end(), [](const pair<int, string>& a, const pair<int, string>& b)
		{
			return a.first < b.first;
		});

	// map�� unordered_map�� key���� �������� ���ĵǾ� ����ȴ�.
	for (auto player : players)
		cout << player.first << ' ' << player.second << '\n';

	return 0;
}