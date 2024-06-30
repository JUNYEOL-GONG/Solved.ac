#include <bits/stdc++.h>
using namespace std;

int N;
int house[1005][3];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : RGB �Ÿ�

	/// 1. ������ �� �б�
	// RGB�Ÿ����� ���� N�� �ִ�.
	// 1�� ������ N�� ���� ������� �ִ�.
	// ���� ����, �ʷ�, �Ķ� �� �ϳ��� ������ ĥ�ؾ� �Ѵ�
	//
	// ���� 1: 1�� ���� ���� 2�� ���� ���� ���� �ʾƾ� �Ѵ�.
	// ���� 2: N�� ���� ���� N-1�� ���� ���� ���� �ʾƾ� �Ѵ�.
	// ���� 3: i(2 �� i �� N-1)�� ���� ���� i-1��, i+1�� ���� ���� ���� �ʾƾ� �Ѵ�.
	//
	// �䱸�ϴ� ��: '��� ���� ĥ�ϴ� ����� �ּڰ��� ���'

	/// 2. �Է°��� �޴´�
	cin >> N;   // ���� ��
	for (int i = 1; i <= N; i++) {   // 1�� ������ N�� ������ RGB ��� ����
		int r, g, b;
		cin >> r >> g >> b;
		house[i][0] = r;
		house[i][1] = g;
		house[i][2] = b;
	}

	/// 3. ������ �м��Ѵ�
	// 26 40 83     // 1�� ��
	// 49 60 57     // 2�� ��
	// 13 89 99     // 3�� ��


	/// DP ���̺� (�迭) �����ϱ�
	// dp[i][j] = i��° ������ ĥ�ϱ� ���� �ּڰ�, �� i��° ���� j�� ĥ������

	/// ��ȭ�� ã�� (+ �ʱ갪 ����)
	//

	int dp[1005][3];

	/* ���ؿ��� Ǭ Ǯ��
	for (int i = 0; i < 3; i++) {
		dp[1][i] = house[1][i];
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = std::min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + house[i][j];
		}
	}
	*/

	// barking dog �� Ǯ��
	// r g b�� 3�� �ۿ� �����ϱ�, ���� for�� �� ������ �̷��� �ϵ��ϰ� �ۼ��ϴ� �� �� �������̰� ȿ�����̴�.

	dp[1][0] = house[1][0];
	dp[1][1] = house[1][1];
	dp[1][2] = house[1][2];

	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
	}

	// 1. 
	// cout << min(dp[N][0], dp[N][1], dp[N][2]);

	// 2.
	cout << *min_element(dp[N], dp[N] + 3);

	return 0;
}
