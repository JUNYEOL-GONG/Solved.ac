#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// �Ž�����

	// 500, 100, 50, 10, 5, 1���� '�����' �ִ�.
	// �Ž������� ������ ���� ���� �ܵ��� �ش�
	// 1000���� ���� ��, �ܵ��� ����

	int payment; cin >> payment;
	int res = 0;

	int rest = 1000 - payment;

	// '���� ���� �ܵ��� �ش�' ��� ����
	// ��ġ�� ū ȭ�� �ִ��� ���� �ָ� �ȴٴ� ���� ����.
	// 500������ 1������ ��ġ�� ū ������ �ش�.

	// �ܿ����� �ִ°�� ����ؼ� �Ž������� ����Ѵ�
	while (rest > 0)
	{
		if (rest - 500 >= 0)
		{
			rest -= 500;
			res++;
		}
		else if (rest - 100 >= 0)
		{
			rest -= 100;
			res++;
		}
		else if (rest - 50 >= 0)
		{
			rest -= 50;
			res++;
		}
		else if (rest - 10 >= 0)
		{
			rest -= 10;
			res++;
		}
		else if (rest - 5 >= 0)
		{
			rest -= 5;
			res++;
		}
		else if (rest - 1 >= 0)
		{
			rest -= 1;
			res++;
		}
	}

	cout << res << endl;

	return 0;
}