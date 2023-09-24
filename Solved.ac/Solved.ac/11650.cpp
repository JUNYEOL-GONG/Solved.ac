#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int L; cin >> L;
	string str; cin >> str;

	// Hashing Function
	// Sigma(ai * r^i) mod M

	long long result = 0;
	long long r = 1;

	// ���ڿ��� �� ��Ҹ� char�� �о�´�
	for (int i = 0; i < L; ++i)
	{
		constexpr int power = 31;

		/// Moduler ������ �й��Ģ�� ����ؾ� �Ѵ�.
		
		// char�� ���������� ǥ���� �Ǵµ� -96�� ���ش�.
		int a = (static_cast<int>(str[i]) - 96) % 1234567891;

		if (i != 0)
			r *= power;

		r %= 1234567891;

		// Hashing �Լ��� ������ result�� �����Ѵ�.
		result += (a * r);
	}

	cout << result % 1234567891 << '\n';

	return 0;
}