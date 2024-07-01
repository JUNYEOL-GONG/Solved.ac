#include <bits/stdc++.h>
using namespace std;

int N, M;
int numArray[100005];   // 10������ int => 40�� byte => 0.4MB�� �޸� ����
int dp[100005];

/*
*
* �޸� ���̾ƿ�
*
���� �ּ�
+------------------+
|       ����       | <- ���� ����, �Լ� ȣ�� ����
|        ��         |
|                  |
|                  |
|        ��         |
|       ��         | <- �������� �Ҵ�� �޸�
+------------------+
|   �̻�� �޸�   |
+------------------+
|     ������       | <- �ʱ�ȭ�� ����/���� ����
+------------------+
|      BSS        | <- �ʱ�ȭ���� ���� ����/���� ����
+------------------+
|     �ؽ�Ʈ       | <- ���α׷� �ڵ�
+------------------+
���� �ּ�
*/
int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ���� �� ���ϱ� 4

	// �� M���� �ٿ� �Է����� �־���
	// i��° ������ j��° ������ ���� ����Ѵ�.

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> numArray[i];
	}

	/*
	while (M--) {
		int i, j;
		cin >> i >> j;

		int sum = 0;

		// i���� j������ ���� ����ϴ� ���� ������ �־��� ��� N�� �ݺ��˴ϴ�
		for (int k = i; k <= j; k++) {
			sum += numArray[k];
		}

		cout << sum << '\n';
	}

	// N: 10��
	// M: 10��

	// O(M * N) => 10�� x 10�� = 10^10 = 100�� ���� ������ �ʿ��ϴ�
	// �ð� ������ 1��
	// ��ǻ���� 1�� ������ ���귮�� �뷫 1���
	// ���� O(N^2) �ð����⵵�� �˰������� �ذ��� �� ����
	*/

	/// ����ؼ� Ǯ�� �˰��� (DP)�� �ذ��ϱ�

	// dp ���̺� �����ϱ�
	// dp[i] = ó������ i��° �������� ���� ��Ƶ� �迭

	// dp[1] = numArray[1]
	// dp[2] = numArray[1] + numArray[2]
	// dp[3] = numArray[1] + numArray[2] + numArray[3]
	// ...
	// dp[i] = dp[i-1] + numArray[i]

	// �� i��° ~ j��° ������ ���� ���ϱ� ���ؼ���
	// 1��° ~ j���� ������ ��
	// - 1��° ~ i-1��° ������ ��
	// = 'i��° ~ j��° ������ ��' �� ����ȴ�

	dp[1] = numArray[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + numArray[i];		// ������ num�� 1000�����̱� ������, 1000�� 10���� ���ص� 1���̱� ������ int ���� �ȿ� ���´�.
	}

	while (M--) {
		int i, j;
		cin >> i >> j;
		cout << dp[j] - dp[i] + numArray[i] << '\n';
	}

	// barking dog�� dp[0] = 0���� �����ϰ�
	// dp[j] - dp[i-1]�� �ذ��ߴ� (�� �� ���)

	return 0;
}
