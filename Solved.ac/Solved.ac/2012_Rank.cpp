#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Abs(int v)
{
	if (v < 0)
		return v *= -1;

	return v;
}

bool AscendingFunc(int a, int b)
{
	return a < b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ��� �ű��

	/*
	 * N : �л� �� (1 <= N <= 500,000)
	 */

	 // �ִ� �Է� Ƚ�� N : 500,000��
	 // �ð� ���� : 2��

	 // ��� ���� �˰����� �ð����⵵ : O(NlgN) �̻�

	int N; cin >> N;

	// �ʿ��� ����
	std::vector<int> guessRankArr(N + 1);
	long long complainValue = 0;

	// ���� ��� �Է�
	for (int i = 1; i <= N; ++i)
		cin >> guessRankArr[i];

	// ���� ��� �������� ����
	/// 0��° �ε����� ������� ���� N + 1���� �迭�� �����ߴµ�, �� �κ��� ����� 0��° �ε����� ������ ������ �����ؾ� �Ѵ�.
	std::sort(guessRankArr.begin() + 1, guessRankArr.end(), AscendingFunc);

	for (int i = 1; i <= N; ++i)
		complainValue += Abs(i - guessRankArr[i]);

	cout << complainValue << '\n';

	return 0;
}