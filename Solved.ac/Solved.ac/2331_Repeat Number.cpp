#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �ݺ� ó���� ���� ����
std::vector<int> visitedVec(1000000, 0);

int SquareFunc(int v, int e)
{
	int res = 1;

	for (int i = 0; i < e; ++i)
	{
		res *= v;
	}

	return res;
}

void DFS(int inputNumber, int p)
{
	visitedVec[inputNumber]++;

	// 3�� �Ǵ� ����, �ݺ��Ǵ� ���� ���� 2�� �������� ������ Stop
	if (visitedVec[inputNumber] > 2)
		return;

	int res = 0;

	while (inputNumber > 0)
	{
		res += SquareFunc(inputNumber % 10, p);
		inputNumber /= 10;
	}

	DFS(res, p);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// ���� �켱 Ž�� (DFS) ����
	// �ݺ� ����

	int A; cin >> A;
	int P; cin >> P;

	// 57, 74, 65, 61, 37, 58, 89, 145, 42 ..
	// 5^2 + 7^2 = 74

	// �ݺ��Ǵ� �κ��� �������� ��, ������ ���� �Ǵ� ������ ������ ���ϴ� ���α׷��� �ۼ�

	// D[n] = D[n-1]�� �� �ڸ��� ���ڸ� P�� ���� ������ ���� ���ϴ� �Լ�
	DFS(A, P);

	int cnt = 0;
	for(const auto v : visitedVec)
	{
		// �ݺ����� ���� ���� ������ ī��Ʈ�Ѵ�.
		if (v == 1)
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}