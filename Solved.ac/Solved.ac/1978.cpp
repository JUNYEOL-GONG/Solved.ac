#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	vector<int> vec;
	int count = 0;

	for (int i = 0; i < N; ++i)
	{
		int value; cin >> value;
		vec.push_back(value);
	}

	// value�� 1000������ �ڿ���
	// �Ҽ��� ã�� ���...?
	for (const auto v : vec)
	{
		if (v == 2)
		{
			count++;
			continue;
		}

		if (v == 1)
		{
			continue;
		}

		bool isPrime = true;

		// 1. 2 ~ v-1 ���� ��� �������� �Ҽ����� �Ǻ�
		for (int i = 2; i < v; i++)
		{
			// i�� �������� �����������??
			// �Ҽ��� �ƴ�
			if (v % i == 0)
			{
				isPrime = false;
				break;
			}

			// ��� �� ���Ҵµ� ������ �������� �ʾҴ�??
			// �Ҽ���

			// �� �ѹ��̶� ������ �������� �Ҽ��� �ƴ�

		}

		if (isPrime)
			count++;
	}

	cout << count << endl;

	return 0;
}