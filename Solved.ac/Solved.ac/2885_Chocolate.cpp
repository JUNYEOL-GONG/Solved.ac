#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ���ݸ� �Ļ�

	/*
	 * K : ��� �Ծ���ϴ� ���ݸ� ���簢�� ����
	 * C : ���� ���� ���ݸ��� ũ��
	 * Cnt : �ɰ��� �ϴ� Ƚ��
	 */

	int K; cin >> K;
	int C = 1;
	int Cnt = 0;

	// ���� ���� ���ݸ��� ũ�� ���ϱ� : K�� ���ų� ū 2�� ������
	while(true)
	{
		if (C >= K)
			break;
		C *= 2;
	}
	const int finalC = C;

	// �ּ� �� �� �ɰ��� �ϴ��� ���ϱ�
	while(K > 0)
	{
		// ���� �κ��� �ٽ� if���� �� ���ش�
		if (K < C)
		{
			C /= 2;
			Cnt++;
		}
		else
		{
			K -= C;
		}
	}

	cout << finalC << " " << Cnt << '\n';

	return 0;
}