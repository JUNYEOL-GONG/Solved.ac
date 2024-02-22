#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : Ű�ΰ�

	// �������� ���� ������ ������ ��ġ���� �߻��Ѵ�
	// ���� ����Ʈ�� ����Ѵ�

	int T; cin >> T;
	while (T--)
	{
		string input; cin >> input;
		int lenght = input.length();

		list<char> myList;
		auto iter = myList.end();	// �ʱ�ȭ�� ���� : iter == myList.begin() == myList.end()

		// �����̰� �齺���̽��� �Է��ߴٸ�, '-'�� �־�����.
		// �̶� Ŀ���� �ٷ� �տ� ���ڰ� �����Ѵٸ�, �� ���ڸ� �����

		for (const auto c : input) {
			if (c == '<') {
				if (iter != myList.begin())
					iter--;
			}
			else if (c == '>') {
				if (iter != myList.end())
					iter++;
			}
			else if (c == '-') {
				if (iter != myList.begin()) iter = myList.erase(--iter);
			}
			else {
				myList.insert(iter, c);
			}

			/*
			* ~ Debug Code ~
			// �� �۾��� iterator�� ���¸� �����ִ� �� �߿��� ������ �Ѵ�
			if (iter == myList.begin()) {
				cout << "iter is begin" << '\n';
			}
			else if (iter == myList.end()) {
				cout << "iter is end" << '\n';
			}
			else {
				cout << "iter value is " << *iter << '\n';
			}
			*/
		}

		for (const auto c : myList) {
			cout << c;
		}

		cout << '\n';
	}

	return 0;
}
