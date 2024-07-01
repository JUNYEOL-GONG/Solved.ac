#include <bits/stdc++.h>
using namespace std;

int N;

void BFS()
{
	queue<pair<int, int>> q;
	q.push({ N, 0 });

	// O(3 �� N) = O( N )
	while (!q.empty()) {
		auto front = q.front(); q.pop();
		if (front.first == 1) {
			cout << front.second;
			break;
		}
		if (front.first % 3 == 0) {
			q.push({ front.first / 3, front.second + 1 });
		}
		if (front.first % 2 == 0) {
			q.push({ front.first / 2 , front.second + 1 });
		}
		q.push({ front.first - 1 , front.second + 1 });
	}
}

bool visited[100005];
bool resArray[100005];
int res = 0x7f7f7f7f;

void CopyArray(bool* from, bool* to, int size) {
	for (int i = 0; i < size; i++) {
		to[i] = from[i];
	}
}

void DFS(int x, int depth)
{
	if (x == 1) {
		if (res > depth) {
			res = depth;
			CopyArray(visited, resArray, 100005);
		}
		return;
	}

	visited[x - 1] = true;
	DFS(x - 1, depth + 1);
	visited[x - 1] = false;

	if (x % 3 == 0) {
		visited[x / 3] = true;
		DFS(x / 3, depth + 1);
		visited[x / 3] = false;
	}
	if (x % 2 == 0) {
		visited[x / 2] = true;
		DFS(x / 2, depth + 1);
		visited[x / 2] = false;
	}
}

int dp[100005];
int pre[100005];	// ��� ������
// pre[i] = i�� ���µ� �������� �� ���� ����

void DP()
{
	// dp[12]�� ���ϰ� �ʹٸ� �Ʒ� �� �ϳ��� ���� ���̴�.
	// -> dp[12 - 1] + 1
	// -> dp[12 / 2] + 1 (���� 2�� �������ٸ� �õ��Ѵ�)
	// -> dp[12 / 3] + 1 (���� 3���� �������ٸ� �õ��Ѵ�)

	dp[1] = 0;	// �ʱ갪: 1�� 1�� ����� �� �ʿ��� �ּ� ���� Ƚ�� (0ȸ)

	// ��ȭ�� ����ϱ�
	for (int i = 2; i <= N; i++) {

		// 1. �⺻���� �־��ش� (3 �Ǵ� 2�� �������� �ʾ��� ��� dp[i]�� dp[i - 1]�κ��� �����ȴ�)
		dp[i] = dp[i - 1] + 1;
		pre[i] = i - 1;	// i�� ���µ� i - 1�κ��� �Դٴ� ������, dp[i]�� pre[i]�� �����Ѵ�

		// 2. 2�� �������� ��� dp[i]�� dp[i / 2]�κ��� �����ȴ�
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {	// min �Լ� ��� dp[i / 2] + 1�� �� ���� ��쿡�� dp[i]�� pre[i]�� �����Ѵ�
			dp[i] = dp[i / 2] + 1;
			pre[i] = i / 2;	// i�� ���µ� i / 2�κ��� �Դٴ� ��
		}

		// 3. 3���� �������� ��� dp[i]�� dp[i / 3]�κ��� �����ȴ�
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {	// min �Լ� ��� dp[i / 3] + 1�� �� ���� ��쿡�� dp[i]�� pre[i]�� �����Ѵ�
			dp[i] = dp[i / 3] + 1;
			pre[i] = i / 3;	// i�� ���µ� i / 3�κ��� �Դٴ� ��
		}
	}

	// N�� 1�̵Ǵ� �� ���� ���� �ּ� ���� Ƚ��
	cout << dp[N] << '\n';

	// N�� 1�� �Ǵ� �� ���� ���� �������� ������ ��θ� ����
	// N
	// cur = pre[N]
	// pre[cur] --> �ݺ�
	// cur == 1�̸� ����

	int cur = N;
	while (true) {
		cout << cur << ' ';
		if (cur == 1)
			break;
		cur = pre[cur];
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 1�� ����� 2

	// X�� 3���� ������ ��������, 3���� ������.
	// X�� 2�� ������ ��������, 2�� ������.
	// 1�� ����.

	// ù° �ٿ� ������ �ϴ� Ƚ���� �ּڰ��� ����Ѵ�.
	// ��° �ٿ��� N�� 1�� ����� ����� ���ԵǾ� �ִ� ���� �������� �����ؼ� ������� ����Ѵ�

	cin >> N;

	// 1. BFS�� �õ��غ��� (���� ����)
	// BFS();

	// 2. DFS�� �õ��غ��� (�ð� �ʰ�)
	/*
	visited[N] = true;
	DFS(N, 0);
	cout << res << '\n';
	for (int i = N; i >= 1; i--) {
		if (resArray[i]) {
			cout << i << ' ';
		}
	}
	*/

	// 3. DP�� �õ��غ���

	// (1): DP ���̺� �����ϱ�
	// dp[i] = i�� 1�� ����� ���� �ʿ��� ������ �ּ� Ƚ��

	// (2): ��ȭ�� ã��
	// dp[12]�� ���ϰ� �ʹٸ�
	// -> dp[4] + 1
	// -> dp[6] + 1
	// -> dp[11] + 1
	// �� �ϳ��� ���� ���̴�.
	//
	// dp[i] = min(dp[4] + 1, dp[6] + 1, dp[7] + 1);
	// -> �̷��� �� �� ����. �ֳ��ϸ� 12�� ���� 3�� ��� ������ ����������
	// 10�� ���� ���ڴ� '/ 3'�� �ȵǱ� ������, ���� üũ�� ����� �Ѵ�

	// (3): �ʱ갪 �����ϱ�

	// �̷��� ���� ��θ� ����ϴ� ������
	// ** �߰������� ������ ��𿣰� �����ؾ� �Ѵ� **

	DP();

	return 0;
}
