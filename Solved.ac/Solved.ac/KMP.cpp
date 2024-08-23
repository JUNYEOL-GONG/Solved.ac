#include <bits/stdc++.h>
using namespace std;

string S;
string P;

vector<int> f;

/// <summary>
/// �κ� ���ڿ��� ���� '���� �Լ�'�� ����Ѵ�
/// </summary>
void CalcFailureFunc(string& subStr) {

	// f(k) : S[0:k+1)���� S[0:x]�� S[x:|S|]�� ��ġ�ϴ� �ִ� ����
	// subStr: 0 1 2 ...| ... k-1 |						=> ���̻� �κ�
	// subStr: 			|0 1 2 ...| ... k-1				=> ���λ� �κ�
	//
	// �������� f(k) <= f(k-1) + 1���� �� �� �ִ�
	// ���� f(k)�� f(k-1) + 1���� �����ϸ� �ִ� ���̸� üũ�Ѵ�
	// 
	// ���� ������ �ٰŷ�, ���� S[f(K-1)] == S[K]���
	// f(k) = f(k-1) + 1�̴�
	//
	// �׷��� �ʴٸ� DP�� ����� �������
	// �̹� ���س��� ���� �̿��ϴ� �� ���� �Լ��� Ű����Ʈ

	int i, j = 0;
	for (i = 1; i < subStr.size(); ++i) {
		while (j > 0) {
			if (subStr[i] == subStr[j]) break;
			j = f[j - 1];
		}
		if (subStr[i] == subStr[j]) {
			f[i] = ++j;
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : �κ� ���ڿ�

	cin >> S;	// ��ü ���ڿ�
	cin >> P;	// �κ� ���ڿ�

	// 1
	// size_t findPos = S.find(P);
	// if (findPos == string::npos)cout << 0;
	// else cout << 1;

	// 2
	// const char* result = strstr(S.c_str(), P.c_str());
	// if (result == nullptr) cout << 0;
	// else cout << 1;

	// 3
	// �Ϲ����� ���ڿ� �˻�(���� ��Ī)�� O(|S1| x |S2|)�� �̷������ (��κ��� ��� ȿ������)
	// ���ڿ��� ���̰� ��ų�, �־��� ��� (���ڿ� S1�� �� ��ġ���� O(|S2|�� �񱳸� �ϴ� ���) �ذ��� �� ����
	//
	// ���� KMT �˰����� ����Ѵ�
	// ���� ��Ī ������ O(|S1| + |S2|)�� �ذ��� �� �ִ�
	// KMT �˰��򿡼��� '���� �Լ�'�� �ٽ��̴�
	// ���� �Լ��� '�κ� ���ڿ����� �ڱ� �ڽ��� �����ϰ� ���λ�� ���̻簡 ��ġ�ϴ� �ִ� ����'�� ����� �����Ѵ�

	f.resize(P.size());
	f[0] = 0;				// S[0:1]������ �ڱ� �ڽŸ� ����
	CalcFailureFunc(P);

	int j = 0;
	for (int i = 0; i < S.size(); ++i) {
		while (j > 0 && S[i] != P[j]) j = f[j - 1];
		if (S[i] == P[j]) ++j;
		if (j == P.size()) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}
