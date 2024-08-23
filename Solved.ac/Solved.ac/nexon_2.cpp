#include <bits/stdc++.h>
using namespace std;

int m, n;
int d[10];

int dp[31];

int result = 0;

void Solution_DFS(int sum, vector<int>& path) {
	// base condition
	if (sum == n) {
		for (int i = 0; i < path.size(); ++i) {
			cout << path[i] << ' ';
		}
		cout << '\n';
		result++;
		return;
	}

	for (int i = 0; i < m; ++i) {
		if (sum + d[i] > n) continue;
		path.push_back(d[i]);
		Solution_DFS(sum + d[i], path);
		path.pop_back();        // backtracking
	}
}

void Solution_DP() {

	// ��� �ֻ��� ���� ����, �ش� ĭ�� �������� �ʱ�ȭ
	for (int i = 0; i < m; ++i) {
		dp[d[i]] = 1;
	}

	// Bottom-Up
	for (int now = 1; now <= n; ++now) {
		for (int i = 0; i < m; ++i) {
			int next = now + d[i];
			if (next <= n) {
				dp[next] += dp[now];
			}
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : �ֻ��� Ż�� ����

	// 1 <= m <= 10
	// 1 <= n <= 30
	// 1 <= d[i] <= 30

	cin >> m;       // �ֻ��� ���� ��
	cin >> n;       // ������ ũ��

	for (int i = 0; i < m; ++i) {
		cin >> d[i];
	}

	/*
	* (1) : DFS (��� �Լ�) Ǯ�̹��
	* Test Case 9���� �ð��ʰ� �߻�(����ȭ �ʿ�)
	*/

	// vector<int> path;
	// Solution_DFS(0, path);

	// cout << result;

	/*
	* (2) : Dynamic Programming (����ؼ� Ǯ��) Ǯ�̹��
	*
	* 1. Dp ���̺� �����ϱ�
	* dp[i]: Ư�� ĭ�� ������ �� �ִ� �ֻ��� ���� ������
	*
	* 2. ��ȭ�� ã��
	* k��° ĭ�� �������� k��° ĭ���� �� �� �ִ� ĭ(k + d[i])�� �����ش�
	* dp[k + d[i]] += dp[k]
	* 
	* 3. �ʱ갪 �����ϱ�
	* �ֻ��� ���� �ش��ϴ� ĭ�� 1�� �ʱ�ȭ�Ѵ�
	*/

	Solution_DP();

	cout << dp[n];

	return 0;
}
