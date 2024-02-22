#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ������

	// ���� �ڷᱸ������ �����͸� ���� / �����Ϸ��� ����
	// N�� ������ �迭�ε� �ذ��� �����ϴ�
	// ������ ���԰� ������ ����� �������� �迭���ٴ� ���� ����Ʈ�� �ذ��ؾ� �Ѵ�

	string input; cin >> input;

	// a -> b -> c -> d
	list<char> strList;
	for (const auto c : input) {
		strList.push_back(c);
	}

	// Ŀ���� ���� ���� ��ġ�Ѵ�
	auto cursorIter = strList.end();

	int M; cin >> M;
	while (M--) {
		char instrument; cin >> instrument;
		switch (instrument) {
		case 'L':
			if (cursorIter != strList.begin())
				cursorIter--;
			break;

		case 'D':
			if (cursorIter != strList.end())
				cursorIter++;
			break;

		case 'B':
			if (cursorIter != strList.begin()) {
				cursorIter--;	// iterator erase (iterator p); ��Ȯ�� p���� ����� ����
				cursorIter = strList.erase(cursorIter);	// �׸��� p���� ����� p�� ���� ��Ҹ� �����´� -> end()
			}
			break;

		case 'P':
			char character; cin >> character;
			strList.insert(cursorIter, character);
			break;
		}
	}

	// iterator based for
	for (const auto c : strList) {
		cout << c;
	}

	return 0;
}
