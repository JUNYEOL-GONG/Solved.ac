#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	std::vector<int> arr;

	int a, b;
	cin >> a >> b;

	// �ִ� ����� ����� ���� ����
	const int abMul = a * b;

	// �ִ� ������� �ּ� �����

	/// a�� b�� �� ������ ���ϱ�

	// 1. b�� ũ��, �� ���� a�� b�� �־��ִ� ���
	if (a < b) std::swap(a, b);

	/// �ִ� ����� ���ϱ�

	// 1 - 1) ���Ʈ���� ��� (��û�� ���)
	/*
	while (a > 0)
	{
		bool hasNum = false;

		// �������� �������� ����� ã�´�
		for (int i = 2; i <= b; ++i)
		{
			// a : 24 b : 12
			// 17 51

			if (a % i == 0 && b % i == 0)
			{
				a /= i;
				b /= i;
				arr.push_back(i);
				hasNum = true;
				break;
			}
		}

		// ����� ���ٸ� ����
		if (!hasNum)
			break;
	}

	// �ִ� ����� ���
	int gcd = 1;
	for (const auto v : arr)
		gcd *= v;
	*/

	// 1 - 2) ���Ʈ���� ��� (�׳��� ���� ���)
	// �׳� ���� �� �������� �������� ���ݾ�.. �� �ٺ���
	/*
	int gcd = 1;
	for (int i = b; i >= 2; --i)
	{
		if ((a % i == 0) && (b % i == 0))
		{
			gcd = i;
			break;
		}
	}
	*/

	// 1 - 3) ��Ŭ���� ȣ����
	// 1. ū ���ڸ� ���� ���ڷ� mod������ �Ѵ�.
	// 2. ���� ���ڸ� 1������ ���� ������ mod������ �Ѵ�.
	// 3. �� ������ mod������ ����� 0�� ���ö� ���� ��� �ݺ��Ѵ�.
	// 4. �̶� ������ ���� ���� ���� �� ���� �ִ������� �ȴ�.
	while (true)
	{
		int c = a % b;

		if (c == 0)
			break;

		a = b;
		b = c;
	}
	int gcd = b;

	// 2) �ִ� ����� ��� (�� ���� ���� �ִ� ������� ������)
	int lcm = abMul / gcd;

	cout << gcd << endl;
	cout << lcm << endl;

	return 0;
}