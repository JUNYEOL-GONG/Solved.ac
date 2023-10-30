#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ī��� ��ǳ

	// TODO : ������ �ذ�������, �� �� ���� Ǫ�� ����� ������� -> vector<bool>�� 3���� ����ߴ�. �ϳ��� vector<int>�� ����ϰ� �� �ȿ� 'ī���� ����'�� �ִ´�

	// ������ �Ϻ� ���� Ȥ�� �� ���¿� ����ؼ� ī���� �ϳ� �� ����忡 ��� �Դ�
	// �ڽ��� �ٷ� �����̳� ���� ����ϴ� �����Ը� ī���� �����ַ��� �Ѵ�
	// �� 4�� ������ ī���� 3�̳� 5���Ը� ������ �� �ִ�
	// �ٸ� �����Լ� ���� ī���� �� �ٸ� ������ ������ �� ����.
	// ī���� �ϳ� �� ������ ���� ī���� �ջ�Ǿ��ٸ�, ������ ī������ ��⿡ �����ϰԵǰ�, �� ī���� �ٸ� ������ ������ �� ����.
	// ī���� �μ��� ���� �ϳ� �� ������ ���� �־�����. ī���� ������ ������ �� ������� ���ϴ� ���� �ּڰ��� �� ������ ���ϴ� ���α׷�

	// �ð� ���� 1��
	// �Է� Ƚ�� N :

	int n; cin >> n;
	int s; cin >> s;
	int r; cin >> r;

	int ableTeam = 0;

	vector<bool> damagedTeam(n + 1);
	vector<bool> additionalTeam(n + 1);
	vector<bool> remainTeam(n + 1, true);

	// �ջ�� ���� ��ȣ
	for (int i = 0; i < s; ++i)
	{
		int teamNum; cin >> teamNum;
		damagedTeam[teamNum] = true;
	}

	// ī���� �� ������ ���� ��ȣ
	for (int i = 0; i < r; ++i)
	{
		int teamNum; cin >> teamNum;
		additionalTeam[teamNum] = true;
	}

	/// ���� ������ ���� ã�°� ������
	///	���� �Ұ����� ���� ã�°� ������

	// ��� ���� ��ȸ�ϸ鼭 ī���� ������ ���� �׳� ���� ������
	for (int i = 1; i <= n; ++i)
	{
		// ī���� �ջ���� �ʾҴٸ� �׳� ���� ����
		if (!damagedTeam[i])
		{
			remainTeam[i] = false;
			ableTeam++;
		}
		// ī���� �ջ������ �߰� ������ �ִٸ� ���� ����
		else if (additionalTeam[i])
		{
			additionalTeam[i] = false;
			remainTeam[i] = false;
			ableTeam++;
		}

		/// �̷��� �ϸ� ���� ī���� �ջ��� ��� �̹� ��������� �߰� ī���� �ִ� ��찡 �����Ѵ�
	}

	for (int i = 1; i <= n; ++i)
	{
		// �����ִ� ���� ��ȸ (ī���� �ջ�Ǿ���, �߰� ī�൵ ���� ���)
		if (remainTeam[i])
		{
			// ���̳� ���� ����
			if (i == 1)
			{
				// ���� ������ ���
				if (!remainTeam[i + 1] && additionalTeam[i + 1])
				{
					ableTeam++;
					additionalTeam[i + 1] = false;
				}
			}
			else if (i == n)
			{

				// ���� ������ ���
				if (!remainTeam[i - 1] && additionalTeam[i - 1])
				{
					ableTeam++;
					additionalTeam[i - 1] = false;
				}
			}
			else
			{
				// ���� ������ ���
				if (!remainTeam[i - 1] && additionalTeam[i - 1])
				{
					ableTeam++;
					additionalTeam[i - 1] = false;
				}
				else if (!remainTeam[i + 1] && additionalTeam[i + 1])
				{
					ableTeam++;
					additionalTeam[i + 1] = false;
				}
			}
		}
	}

	cout << n - ableTeam << '\n';

	return 0;
}