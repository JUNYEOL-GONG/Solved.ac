#include <bits/stdc++.h>
using namespace std;

int a[10];
int sum = 0;
pair<int, int> two;
vector<int> vec;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : �ϰ�������

	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}

	// 9���� ������ �� 2������ ��� Ű�� ��ģ��
	// ��ģ Ű�� ��ü Ű�� �տ��� ����, �� ���� 100�̶�� ���
	for (int x = 0; x < 9; x++) {
		for (int y = x + 1; y < 9; y++) {		// i�� 0 ~ 9���� ���µ�, j�� 1 ~ 9, 2 ~ 9, 3 ~ 9, 4 ~ 9, ... , 9 ~ 9�� �ߺ��� �񱳸� ���Ѵ�
			if (sum - (a[x] + a[y]) == 100) {
				two = { x, y };
				goto end;
			}
		}
	}

	end:

	for (int t = 0; t < 9; t++) {
		if (two.first == t || two.second == t)
			continue;
		vec.push_back(a[t]);
	}

	std::sort(vec.begin(), vec.end());

	for (auto v : vec) {
		cout << v << '\n';
	}

	return 0;
}
