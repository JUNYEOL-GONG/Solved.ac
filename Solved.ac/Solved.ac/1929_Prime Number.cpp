#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

void Solution(int start, int end)
{
	// start���� end���� �Ҽ��� ��� �������

	// �Ҽ� �Ǵܹ�
	// �Ҽ� : N�� ��� 1�� N���� ���

	for (int number = start; number <= end; ++number)
	{
		bool isPrime = true;

		if (number == 1)
			continue;

		if (number == 2 || number == 3)
		{
			cout << number << '\n';
			continue;
		}

		// �ڽ��� �����ٱ��� ��������
		for (int div = 2; div * div <= number; ++div)
		{
			if(number % div == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
			cout << number << '\n';
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : �Ҽ� ���ϱ�

	int M, N;
	cin >> M >> N;

	// M�̻� N������ �Ҽ��� ��� ���
	Solution(M, N);

	return 0;
}
