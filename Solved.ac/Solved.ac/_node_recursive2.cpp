#include <bits/stdc++.h>
using namespace std;

/// <summary>
/// ���� �⺻���� �������, ���� ���ݸ� Ŀ����
/// 1. int�δ� �ذ��� �� ���ٴ� ��������
/// 2. O(N)�� �ð����⵵��� �������� �����Ѵ�.
/// 
/// 10 10 7 �� input���� ������ 1�� ���������� ���� �ذ��� �Ұ���
/// 
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
/// <param name="C"></param>
/// <returns></returns>
int func_1629_1(int A, int B, int C)
{
	int result = 1;
	while (B--) result *= A;
	return result % C;
}

/// <summary>
/// �������� ����� �����ϴ� ������� ����
/// 1�� ������ �ذ�� ���
/// 
/// 10 10 7 �� �ذ�ȴ�
/// 
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
/// <param name="C"></param>
/// <returns></returns>
int func_1629_2(int A, int B, int C)
{
	int result = 1;
	while (B--) result = result * A % C;	// �������� �����
	return result;
}

using ll = long long;
/// <summary>
/// ���� �˾�����, ���� 1�� ������ �Ϻ��ϰ� �ذ���� �ʾҴ�
/// A, B, C�� ���� INT_MAX�� �Ѿ�ٸ� ��ȿ���� �����Ƿ� long long type�� ����Ѵ�
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
/// <param name="C"></param>
/// <returns></returns>
ll func_1629_3(ll A, ll B, ll C)
{
	ll result = 1;
	while (B--) result = result * A % C;	// �������� �����
	return result;
}

/// <summary>
/// ���� 2�� �������� �ذ��ؾ� �ϴµ�,
/// �ð� ���� 0.5��, N: 2147483647 (�� 21��)�� ���,
/// 
/// 1�ʿ� ��ǻ�Ͱ� ������ �� �ִ� Ƚ�� �� 1��� (10^8)
/// ���� �ش� ������ O(N)���� �ذ��� �� ������,
/// 
/// O(logN)�� �ð� ���⵵�� �ذ��ؾ� �ϴ� �����̴�.
/// 
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
/// <param name="C"></param>
/// <returns>A^B % C�� ����� ������� ��ȯ�Ѵ�</returns>
ll func_1629_4(ll A, ll B, ll C)
{
	// ��� �ϸ� O(logN)�� �ð� ���⵵�� ����� �� ������?

	// ������ ������ �̿��Ѵ�
	// 1. a^n + a^n = a^2n
	// 2. a^b % c = x^1 �̶�� a^2b % c = x^2�� �ȴ�.

	// 2�� ������ ���� ����
	// x % y = z��� ������,
	// x = z + ky
	// x^2 = (z + ky)^2
	// x^2 = z^2 + 2zky + (ky)^2
	// -> 2zky + (ky)^2 �κ��� y�� ������ �������Ƿ�
	// => x^2 % y = z^2�� �ȴ�.

	// ������ �ͳ��� ����� �̿�
	// A^1 % C = ?�� ���� �� �ְ�,
	// A^k % C = ?�� ���� �� �ְ�,
	// A^(2k) % C = ?�� ���� �� �ִٸ�,	// ¦��
	// A^(2k+1) % C = ?�� ���� �� �ִ�.	// Ȧ��

	// base condition
	if (B == 0) return 1;
	// x^2 % y = z^2 => x % y = z
	ll result = func_1629_4(A, B / 2, C);
	result = result * result % C;
	if (B % 2 == 0) return result;			// A^B % C �� ���� ���� ��ȯ�Ѵ�.
	return result * A % C;					// A^(B+1) % C �� ���� ���� ��ȯ�Ѵ�.
}

void Solve_1629()
{
	int A, B, C; cin >> A >> B >> C;
	cout << func_1629_4(A, B, C);
}

int main()
{
	Solve_1629();


	return 0;
}