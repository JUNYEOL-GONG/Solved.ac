#include <bits/stdc++.h>
using namespace std;

int n;

int res = 0;

void Recursive(int cur)
{
	// ����� �ϳ� ã�� ���̴�
	if (cur == n) {
		res++;
		return;
	}

	// �� ����� �ƴ� ���̴�
	if (cur > n) {
		return;
	}

	for (int i = 1; i <= 3; i++) {
		Recursive(cur + i);
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 1, 2, 3 ���ϱ�

	// 1. ���̺��� �����Ѵ�
	// -> dp[i] -> i�� 1, 2, 3�� ������ ��Ÿ���� ����� ��
	// 
	// 2. ��ȭ���� ã�´� (
	// -> dp[4]�� ���ϰ� �ʹٸ�,
	// --> dp[3] // (1+1+1)+1, (3)+1, (2+1)+1, (1+2)+1 ==> Dp[3] = 4
	// --> dp[2] // (1+1)+2, (2)+2 ==> Dp[2] = 2
	// --> dp[1] // (1)+3 => Dp[1] = 1
	// // -> dp[4] = dp[3] + dp[2] + dp[1]
	// 
	// dp[k] = dp[k-1] + dp[k-2] + dp[k-3]
	// 
	// 3. �ʱ갪�� �����Ѵ�
	//
	// dp[1] = 1 // 1�� 1, 2, 3�� ������ ��Ÿ���� ����� ��
	//

	// dp�� �� �ִ� ���� �ٲ��� �ʴ´�.
	int dp[15];

	// ** ������ �ʱ갪�� �����Ǿ�� �ϴ��� �� �ƴ� ���� �߿��ϴ� **
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	// ** �̸� ����� �صд�. �׽�Ʈ ���̽��� ������������ �� ���� ����صθ� ����ؼ� ����� �� �ִ� **
	for (int i = 4; i <= 11; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	int T;  cin >> T;
	while (T--) {
		cin >> n;


		// ���� ���α׷��� ��� (�ſ� ȿ����)
		cout << dp[n] << '\n';


		// ����Լ� ��� (�ſ� ��ȿ����)
		// Recursive(0);
		// cout << res << '\n';
		// res = 0;
	}

	return 0;
}
