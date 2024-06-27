#include <bits/stdc++.h>
using namespace std;

int N, M;
int cards[10];
int res[10];
bool isUsed[10];

void Func(int curCount) {
	if (curCount == M) {
		for (int i = 0; i < curCount; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int temp = -1;
	for (int i = 0; i < N; i++) {
		if (isUsed[i]) continue;
		if (temp == cards[i]) continue;
		if (curCount > 0) {
			if (cards[i] < res[curCount - 1])
				continue;
		}
		temp = cards[i];
		res[curCount] = cards[i];
		isUsed[i] = true;
		Func(curCount + 1);
		isUsed[i] = false;
	}
}
int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : N�� M (10)

	// 1. �� ������ �񳻸������̾�� �Ѵ�.
	// => ���̰� K�� ���� A�� A1 �� A2 �� ... �� AK-1 �� AK�� �����ϸ�, �񳻸������̶�� �Ѵ�.

	// 2. ���� ���� �Էµ� �� �ִ�

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}
	std::sort(cards, cards + N);
	Func(0);
	return 0;
}
