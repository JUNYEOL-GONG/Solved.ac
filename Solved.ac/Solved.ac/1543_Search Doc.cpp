#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// ���� Ž��

	// � �ܾ �� �� �� �����ϴ���

	// �ߺ��Ǿ� ���� ���� ����.
	// abababa = ababa x 2 -> X

	// iostream �ȿ� �ִ� �Է� ��Ʈ�� ��ü cin�� ������ �����ϰ� �Է¹޴´�.
	// string�� getline()�� ����Ѵ�.

	string str; getline(cin, str);
	string word; getline(cin, word);

	int cnt = 0;

	// ��� 1 : ���Ʈ���� ������� Ǫ�� ���
	/*
	for (int i = 0; i < str.length(); ++i)
	{
		bool isContain = true;

		// �� �ܾ ���� ���Ƽ� �´��� Ȯ���Ѵ�.
		for (int j = 0; j < word.length(); ++j)
		{
			if (str[i + j] != word[j])
			{
				isContain = false;
				break;
			}
		}

		// �� ������ üũ
		if (isContain)
		{
			cnt++;
			i += word.length() - 1;
		}
	}
	*/

	// ��� 2 : �׸��� �˰������� Ǫ�� ���..?
	// -> �̰� �߸� ���� �����ε� �ϴ�

	// ��� 3 : string Ŭ������ ���� Ȱ���ϴ� ���..?


	cout << cnt << endl;

	return 0;
}