#include <bits/stdc++.h>
using namespace std;

int N, M;
int answerArray[10];
int inputArray[10];

void Func(int curCount) {
	if (curCount == M) {
		for (int i = 0; i < curCount; i++) {
			cout << answerArray[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		int targetNumber = inputArray[i];
		if (curCount > 0) {
			if (answerArray[curCount - 1] >= targetNumber)
				continue;
		}
		answerArray[curCount] = targetNumber;
		Func(curCount + 1);
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : N�� M (6)

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> inputArray[i];
	}

	// �Է°� ������������ �����ϱ�
	std::sort(inputArray, inputArray + N);

	// 0������ ����
	Func(0);

	return 0;
}
