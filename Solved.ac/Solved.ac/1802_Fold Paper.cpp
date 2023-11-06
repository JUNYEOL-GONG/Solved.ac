#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// ���� ���� �������� �Ǵ��ϴ� �Լ�
/// </summary>
/// <param name="_foldInfo"></param>
/// <returns></returns>
bool Check(string _foldInfo)
{
	size_t vertexCnt = _foldInfo.length();
	size_t middleIndex = vertexCnt / 2;

	// ���̻� ���� �� ���������� ���� ���� �ݺ�
	while (middleIndex != 0)
	{
		// 2. �߰��� �������� ���� ������ ��Ī�� ������ Ȯ���Ѵ�
		for (size_t i = 0; i < middleIndex; ++i)
		{
			// �ϳ��� ��Ī�� �ƴ϶�� ������ �ʴ´�
			if (_foldInfo[i] + _foldInfo[vertexCnt - 1 - i] != 97)
				return false;
		}

		// �� ������ �߰������� ���´�.
		vertexCnt /= 2;
		middleIndex /= 2;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ���� ����

	/// �� ������ �׸��� �˰��� �з����� ����..?
	///	�������� ���� ���� ���������� ���� ��찡 �ִµ� �� ������ ������� �ʰ� ��Ī �񱳷θ� �����ؼ�..?
	///	��.. �ƴѰŰ�����,,, �׳� �������� ������� �ϴ°� �´� �� ����. -> �׸��� �˰��� ���� X
	///	�������� ����Լ��� �̿��ؼ� �� ������ Ǯ���..

	/*
	 * T : �׽�Ʈ ���̽� ��
	 */

	int T; cin >> T;

	for (int i = 0; i < T; ++i)
	{
		string foldInfo; cin >> foldInfo;

		// ������ ��� ����
		if (foldInfo.length() == 1)
		{
			cout << "YES" << endl;
			continue;
		}

		/// ���ڿ��� YES / NO �� �ƴ϶� Yes / No��� �ߴٰ� Ʋ�ȴ��.. �� ����..
		string str = (Check(foldInfo) == true) ? "YES" : "NO";
		cout << str << endl;
	}

	return 0;
}