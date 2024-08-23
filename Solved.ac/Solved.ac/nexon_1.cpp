#include <bits/stdc++.h>
using namespace std;

int N, Q;
string M;
int S, E;
vector<int> preSum;

int Solution(string m, int s, int e) {

	int left = s;
	int right = e;

	// ���ʿ������� ù��° '*'�� ã�´�
	while (left <= e && M[left] != '*') {
		left++;
	}

	// �����ʿ������� ù��° '*'�� ã�´�
	while (right >= s && M[right] != '*') {
		right--;
	}

	// �����ߴٴ� ���� �ŵ��� �������� �ʴ´ٴ� ����
	if (left > right) return 0;

	// �̸� ����ص� ���� �̿��� ������ ���� ���
	return preSum[right + 1] - preSum[left];
}

/// <summary>
/// ��ü ���ڿ��� ���� preSum�� ����ϴ� �Լ�
/// </summary>
void PreSumProcess() {
	preSum.resize(N + 1, 0);			// ����� ���Ǽ��� ���� 0�� �ε����� ����д�
	for (int i = 0; i < N; ++i) {
		preSum[i + 1] = preSum[i];		// ���� ���� �����´�
		if (M[i] == '*') continue;		// '*'�� ���� ���� ������ �ִ� ���¿��� �ӹ���
		preSum[i + 1] += M[i] - '0';	// ���� ���� ������Ų��
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ������ �����̶�

	cin >> N;       // ���ڿ� ����
	cin >> M;       // ���ڿ�
	cin >> Q;       // �ڸ��� Ƚ��

	PreSumProcess();

	while (Q--) {
		cin >> S >> E;
		cout << Solution(M, S, E) << '\n';
	}

	return 0;
}