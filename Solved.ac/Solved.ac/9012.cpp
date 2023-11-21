#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace std;

string VPS_Cheack(string& input)
{
	// ������ ¦�������� �Ѵ�
	if (input.length() % 2 != 0)
		return "NO";

	// ������ �̿��ؼ� ��ȣ ���ڿ��� �˻��Ѵ�
	std::stack<char> vpsStack;
	for (int i = 0; i < input.length(); ++i)
	{
		// '('�� ��쿡�� push ���ش�
		if(input[i] == '\(')
		{
			vpsStack.push(input[i]);
		}
		// ')'�� ��쿡�� pop ���ش�
		else if (input[i] == '\)')
		{
			// ���� �ȿ� '('�� �ִ� ��쿡�� pop ���ش�
			if (!vpsStack.empty())
				vpsStack.pop();
			// ���� �ȿ� �ƹ��͵� ������ ��ȿ���� �����Ƿ� NO
			else
				return "NO";
		}
	}

	// ������ ��������� ������ ���� �̷�����ٴ� ��
	if (vpsStack.empty())
		return "YES";

	return "NO";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ��ȣ

	int T; cin >> T;

	while(T-- > 0)
	{
		string input; cin >> input;
		cout << VPS_Cheack(input) << endl;
	}

	return 0;
}