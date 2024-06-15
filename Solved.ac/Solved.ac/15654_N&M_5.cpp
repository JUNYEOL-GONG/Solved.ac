#include <bits/stdc++.h>
using namespace std;

int N, M;
int answerArray[10];
int storageArray[10];
bool isUsed[10005];

void Func(int curCount) {

	if (curCount == M) {
		for (int i = 0; i < curCount; i++) {
			cout << answerArray[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// DFS ������� ������ ����
	// �׷��� ������ ���� ������ myArray�� ����� �� �ִ� (����� �������)

	// �������� ���ĵǾ��ִ� ���ڵ��� �ϳ��� ������
	for (int targetIndex = 0; targetIndex < N; targetIndex++) {
		int targetNumber = storageArray[targetIndex];
		if (isUsed[targetNumber]) continue;
		answerArray[curCount] = targetNumber;
		isUsed[targetNumber] = true;			// ��Ʈ��ŷ�� ����Ʈ
		Func(curCount + 1);
		isUsed[targetNumber] = false;			// ��Ʈ��ŷ�� ����Ʈ
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : N�� M (5)

	// 1. 1���� N���� �ڿ��� �߿��� M���� �� ����

	// 2. N���� �ڿ����� ��� �ٸ� ���̴�.

	// 3. N���� ���� �־�����.
	// => �Է����� �־����� ���� 10,000���� �۰ų� ���� �ڿ����̴�.

	// 4. �Ȱ��� ���� ����ϸ� �ȵȴ�.

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> storageArray[i];
	}

	// �������� ���� (NlogN)
	std::sort(storageArray, storageArray + N);

	Func(0);

	return 0;
}
