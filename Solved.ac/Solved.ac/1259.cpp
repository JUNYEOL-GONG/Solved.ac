#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// �Ӹ���Ҽ�
	// ���ǹ��� 0�� �տ� �� �� ���ٰ� ����.

	while (true)
	{
		string integer; cin >> integer;

		if (integer == "0")
			break;

		string answer = "yes";

		for (int i = 0; i < integer.length(); ++i)
		{
			if (integer[i] != integer[integer.length() - 1 - i])
			{
				answer = "no";
				break;
			}
		}

		cout << answer << endl;
	}


	return 0;
}