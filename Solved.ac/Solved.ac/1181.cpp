#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::ios;
using std::cin;
using std::cout;
using std::string;

bool Compare(string a, string b)
{
	// ���̰� ª�� �ͺ���
	// ���̰� ������ ���� ������

	if (a.length() == b.length())
	{
		for (int i = 0; i < a.length(); ++i)
		{
			if (a[i] == b[i])
				continue;

			return a[i] < b[i];
		}
	}

	return a.length() < b.length();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// �ܾ� ����

	int N; cin >> N;

	string wordsArr[20000];

	for (int i = 0; i < N; ++i)
	{
		string word; cin >> word;
		wordsArr[i] = word;
	}

	std::sort(wordsArr, wordsArr + N, Compare);

	for (int i = 0; i < N; ++i)
	{
		// ���� ��Ұ� ���� ��Ҷ� ���� ���̸� �Ѿ��
		if (wordsArr[i] == wordsArr[i + 1])
			continue;

		if (!wordsArr[i].empty())
			cout << wordsArr[i] << '\n';
	}

	return 0;
}