#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Solution(int& x)
{
	int cnt = 0;

	// x -> 1
	while (x != 1)
	{
		// 3���� ������ �������� 3���� ������
		if (x % 3 == 0)
		{
			x /= 3;
		}
		// 2�� ������ �������� 2�� ������
		else if (x % 2 == 0)
		{
			x /= 2;
		}
		// 1�� ����
		else
		{
			x -= 1;
		}

		// ������ ����� Ƚ�� ����
		cnt++;
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;

	// ������ �ϴ� �ּ� Ƚ���� ���
	std::cout << Solution(N) << std::endl;

	return 0;
}