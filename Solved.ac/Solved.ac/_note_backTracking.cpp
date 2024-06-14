#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// back tracking
// : '���� ����'���� '������ ��� �ĺ���'�� ���� ���� Ž���ϴ� �˰���

// �̿����� �������� ����, '���� ���¿��� ������ ��� ������'�� �� �÷��� �غ��� ���..?
//
// �Ǵ� ������ �δ� ���, '����'�� �дٸ� �׿� �ش��ϴ� ��� ����� ���� Ž���ϰ� ������ ���� �α� ���� '�ٽ� ���ƿ´�'
//

/// <summary>
/// �ͳ��� ��������� ���丮�� �ذ��ϱ�
/// 
/// 1. factorial(0) = 1
/// 2. factorial(1) = 1 * factorial(0)
/// 3. factorial(2) = 2 * factorial(1)
/// 4. factorial(3) = 3 * factorial(2)
/// 5. factorial(4) = 4 * factorial(3)
/// ...
/// K. factorial(K) = K * factorial(K-1)
/// K+1. factorial(K+1) = (K+1) * factorial(K)
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int Factorial(int n) {
	// base condition
	if (n == 0) return 1;
	return n * Factorial(n - 1);
}

int Func_Test(int n, int m)
{
	// 1���� N���� '�ߺ� ����' M���� �� ������ ��� ����� �� ã��
	// 
	// nPm = p(n,m) = n! / (n-m)!
	int numerator = Factorial(n);
	int denominator = Factorial(n - m);
	return numerator / denominator;
}

int N, M;
int arr[10];
bool visited[10];
void Recursive1(int count) {
	// base condition
	if (count == M) {
		for (int index = 0; index < count; index++) {
			cout << arr[index] << ' ';
		}
		cout << '\n';
		return;
	}
	// 1���� N���� ��ȸ
	for (int number = 1; number <= N; number++) {
		if (visited[number]) continue;
		visited[number] = true;
		arr[count] = number;
		Recursive1(count + 1);
		arr[count] = -1;
		visited[number] = false;
	}
}

void Solve_15649()
{
	cin >> N >> M;

	fill(arr, arr + 10, -1);
	Recursive1(0);

	// Func_Test(N, M);
}

int S;
int cnt = 0;
int arr2[21];
void Recursive2(int curIdx, int sum)
{
	// ��� ����� ���� ��ȸ���� ��� (���԰� �������� ������ ��ħ)
	if (curIdx == N) {
		if (sum == S) {
			cnt++;
		}
		return;
	}

	// arr[curIdx]�� ���� ���� ������ ���� Ž���Ѵ�
	Recursive2(curIdx + 1, sum); // �������� �ʰ� �״�� �Ѱ��ش�
	Recursive2(curIdx + 1, sum + arr2[curIdx]); // ���� �����ִ� ���� ������ ���� �Ѱ��ش�

	// �ᱹ 2^N�� ����� ���� ��� Ž���Ѵ�.
}

void Solve_1182()
{
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr2[i];
	}

	Recursive2(0, 0);

	// S�� 0�� ��쿡�� �������� ��쿡�� cnt++�� �Ǳ� ������ ���� ó���� ����� �Ѵ�.
	if (S == 0) cnt--;

	cout << cnt;
}

// ��ġ�� ���� ����� �ܺ� ������ �����Ѵ�
typedef pair<int, int> pos;
stack<pos> myStack;

void Recursive3(int count)
{
	// base condition
	if (count == N) {
		cnt++;
		return;
	}

	// ��ġ�� �� �ִ��� �Ǵ��Ѵ�

	// 1. ���� ���� ������ �ȵ�
	// 2. �밢���� ������ �ȵ� (���� �Ʒ� �밢��, ������ �Ʒ� �밢��)
}

void Solve_9663()
{
	cin >> N;

	Recursive3(0);

	cout << cnt;
}

int main()
{
	Solve_9663();


	return 0;
}