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
		if (v == 1)
			continue;

		if (v == 2)
		{
			count++;
			continue;
		}

		bool isPrime = true;

		for (int i = 2; i * i <= v; i++)
		{
			if (v % i == 0)
				isPrime = false;
		}

		if (isPrime)
			count++;
	}

	cout << count << endl;

	return 0;
}