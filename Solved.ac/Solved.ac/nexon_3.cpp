#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int a, b;

constexpr char odd[8] = { 'b', 'd', 'g', 'n', 'p', 'r', 's', 't' };
constexpr char even[5] = { 'a', 'e', 'i', 'o', 'u' };

// �ð� ���⵵ O(1)�� ����, ����, Ž�� (�ߺ� ��� x)
unordered_set<string> candidates;

pair<int, int> GetStrikeBall(const string& s, const string& candidate) {
	int strike = 0, ball = 0;
	for (int i = 0; i < 4; ++i) {
		if (s[i] == candidate[i]) strike++;
		else if (candidate.find(s[i]) != string::npos) ball++;
	}
	return { strike, ball };
}

/// <summary>
/// �ĺ��� ���͸� �Լ�
/// �ĺ����� �����̶�� '����'�Ѵٸ�, ������ �ĺ����� ����� ��ġ�ؾ� �Ѵ�
/// ����� ���ٴ� ���� '������ ���ɼ��� ����'�� �ǹ��Ѵ�.
/// �ݴ�� ����� �ٸ��ٴ� ���� '����� ������ �� ����'�� �ǹ��Ѵ�.
/// </summary>
void Solution(const string& s, const int& a, const int& b) {
	for (auto iter = candidates.begin(); iter != candidates.end();) {
		const auto result = GetStrikeBall(s, *iter);
		if (result.first != a || result.second != b) iter = candidates.erase(iter);
		else ++iter;
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ���� �̸� ���߱�
	// ��ǻ� ���� �߱��� ���ĺ� ����

	// �̸��� 1��°�� 3��°�� ���� �ٸ� 'b', 'd', 'g', 'n', 'p', 'r', 's', 't'
	// �̸��� 2��°�� 4��°�� ���� �ٸ� 'a', 'e', 'i', 'o', 'u'

	/// [Ǯ�� ���]
	/// n���� ���� �Ŀ� ������ O(1)�� �������� �Ѵٴ� ���� ����Ʈ
	/// �ᱹ �ĺ����� �̿��� ���͸�(�ҰŹ�) ����� ���

	// ������ ��� ���� �̸� �ĺ����� Ȯ��
	candidates.reserve(8 * 7 * 5 * 4);	// 8P2 * 5P2
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (i == j) continue;
			for (int k = 0; k < 5; ++k) {
				for (int l = 0; l < 5; ++l) {
					if (k == l) continue;
					candidates.insert({ odd[i] , even[k] , odd[j] , even[l] });
				}
			}
		}
	}

	cin >> n;       // ���� ��

	while (n--) {
		cin >> s >> a >> b;
		Solution(s, a, b);
	}

	if (candidates.size() > 1) cout << 'x';
	else if (candidates.size() == 1) cout << *candidates.begin();
	else cout << 'x';

	return 0;
}
