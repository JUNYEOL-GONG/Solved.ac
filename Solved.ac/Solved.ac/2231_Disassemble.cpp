#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ������

	int N; cin >> N;

	// M�� N�� ������
	// M : 245 N : 256 (245 + 2 + 4 + 5)

	// 216�� �־������� ���� ���� �����ڸ� ���ϴ� ���

	// ���� ó�� �ȵ� �� ���� ���
	int min = INT32_MAX;
	bool hasAnswer = false;

	for (int c = N; c >= 1; --c)
	{
		int result = c;
		int tempC = c;

		while (tempC != 0)
		{
			result += tempC % 10;
			tempC /= 10;
		}

		// �����ڰ� �ִ� ���
		if (result == N)
		{
			hasAnswer = true;

			if (min > c)
				min = c;
		}
	}

	if (hasAnswer)
		cout << min << '\n';
	else
		cout << 0 << '\n';



	return 0;
}
