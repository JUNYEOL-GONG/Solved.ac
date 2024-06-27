#include <bits/stdc++.h>
using namespace std;

int N, M;
bool isUsed[10];
int answerArray[10];

void Func(int curCount)
{
	// 1���� N���� �ڿ��� �߿��� '�ߺ� ����' M���� �� ����
	// �� ������ ���������̾�� �Ѵ�.

	// M���� �迭�� ����Ѵ�
	if (curCount == M)
	{
		// �迭�� ���ϴ� ������ ��Ұ� �� ��, �ѹ��� ����Ѵ�
		for (int i = 0; i < curCount; i++) {
			cout << answerArray[i] << ' ';
		}

		cout << '\n';

		return;
	}

	for (int number = 1; number <= N; number++) {

		// �̹� ���� ���̸� ��ŵ
		if (isUsed[number]) continue;

		// �̹� 1���� �����ϴ� ��쿡 ���� �߰��Ϸ��� ���� �� ū�� Ȯ���Ѵ�
		if (curCount > 0) {
			if (answerArray[curCount - 1] > number)
				continue;
		}

		answerArray[curCount] = number;

		isUsed[number] = true;
		Func(curCount + 1);
		isUsed[number] = false;
	}
}

void Func2(int curCount, int startNumber)
{
	if (curCount == M)
	{
		// �迭�� ���ϴ� ������ ��Ұ� �� ��, �ѹ��� ����Ѵ�
		for (int i = 0; i < curCount; i++) {
			cout << answerArray[i] << ' ';
		}

		cout << '\n';

		return;
	}

	for (int number = startNumber; number <= N; number++) {
		answerArray[curCount] = number;
		Func2(curCount + 1, number + 1);        // ���� ���� �� �� ���� ������ ū ������ �����ϵ��� �߽��ϴ�. (�������� �ذ�)
	}
}

bool isAlreadyUsed[10];
int resultArray[10];
void Func3(int curCount, int start)
{
	// M���� ��� �����
	if (curCount == M) {
		for (int i = 0; i < curCount; i++) {
			cout << resultArray[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// ��Ʈ��ŷ�� �̿��� Ǯ��
	for (int i = start; i <= N; i++) {
		if (isAlreadyUsed[i]) continue;
		resultArray[curCount] = i;
		isAlreadyUsed[i] = true;
		Func3(curCount + 1, i + 1);
		isAlreadyUsed[i] = false;
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : N�� M (2)

	cin >> N >> M;

	Func2(0, 1);
	// Func3(0, 1);

	/*
	std::vector<int> arr(N, 1);
	for (int i = 0; i < M; i++) {
		arr[i] = 0;
	}

	do
	{
		for (int i = 0; i < N; i++) {
			if (arr[i] == 0) {
				cout << i + 1 << ' ';
			}
		}
		cout << '\n';
	} while (std::next_permutation(arr.begin(), arr.end()));
	*/

	return 0;
}
