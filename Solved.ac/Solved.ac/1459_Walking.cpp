#include <iostream>

#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// �ȱ�

	// �б�(0,0) -> ��(x,y)
	// ���� / ���� / �밢�� �̵� ����
	// ������ ���µ� �ɸ��� '�ּ� �ð�'?

	// ���� ��ġ X, Y
	// �� ��� ���µ� �ɸ��� �ð� W
	// �� ��� �밢�� �̵� �ð� S

	// �ð� ���� : 2��
	// 1 <= x,y <= 10��
	// 1 <= w,s <= 10000
	// ��û Ŀ�ٶ� ���� ������ ���� ���̹Ƿ� long long�� ����Ѵ�.

	long long x, y; cin >> x; cin >> y;
	long long w, s; cin >> w; cin >> s;

	// �� ū ���� �����ʿ� �д�.
	// std::max or std::min ������ ������� �ʾƵ� �ȴ�.
	if (x > y)
		std::swap(x, y);

	// �� �̵��� �ϴ� ���
	long long res = (x + y) * w;

	/// ����� ���� �Ϻ��ϰ� ������..
	/// �ʹ� �ȴ� ����� ��,, ������ �Ĳ��ϰ� �����ϰ� �Ϻ��ϰ� �����ؾ��Ѵ�. �ݷʱ���

	// �밢�� �̵��� �ϴ� ���
	if (s < 2 * w)
	{
		// �밢���� �� ���� ���
		if (s > w)
		{
			res = x * s + (y - x) * w;
		}
		// �밢���� �� ���� ���
		else
		{
			// ¦�����
			if ((x + y) % 2 == 0)
			{
				res = y * s;
			}
			// Ȧ�����
			else
			{
				res = (y - 1) * s + w;
			}
		}
	}

	cout << res << endl;

	return 0;
}