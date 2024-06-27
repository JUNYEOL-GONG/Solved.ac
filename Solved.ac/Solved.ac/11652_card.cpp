#include <bits/stdc++.h>
using namespace std;

int N;
long long cards[100005];

// 256MB = 256x 10^6 Byte
// 256 / 4 = 64
// 64 x 10^6���� ��Ҹ� ���� �迭�� ������ �� ����
// 1 x 10^5���� ������� ���� ����

void Solution1() {	// O(N^2)

	// ���� ���� ������ �ִ� ī�忡 ���� ����
	long long most_frequent_number = cards[0];

	// �� ������ ���� Ƚ��
	int maxCount = 1;

	// ī�带 ��ȸ�Ѵ�
	for (int i = 0; i < N; i++) {
		int count = 1;
		// �ش� �ε����� ī��� ������ ������ ���� ī�带 �߰��ϸ� ������ ������Ų��.
		for (int j = 0; j < N; j++) {
			if (cards[i] == cards[j]) {
				count++;
			}
		}
		// ������ �� ���������� ������ ������ �����Ѵ�
		if (count > maxCount) {
			maxCount = count;
			most_frequent_number = cards[i];
		}
		// ������ ���� �������� �� �۴ٸ� �����Ѵ�
		else if (count == maxCount && cards[i] < most_frequent_number) {
			most_frequent_number = cards[i];
		}
	}

	cout << most_frequent_number;
}

void Solution2() {

	// ������������ ���ĵ� ������ �迭�� �����
	std::sort(cards, cards + N);

	// ù��° ��Ҹ� �ִ´�
	long long most_freq_num = cards[0];

	int maxCount = 0;
	int curCount = 1;	// ù���� ����� ������ �̹� �ô�

	// ī�带 ��ȸ�Ѵ�
	for (int i = 1; i < N; i++) {
		// ���ӵ� ���� ���ڵ鿡 ���ؼ� ������ ������Ų��
		if (cards[i] == cards[i - 1])
			curCount++;
		// �������� ���� ���ڰ� �����ߴٸ�
		else {
			// �׸��� �׵��� �׾ƿ� ������ �ִ� �������� ũ�ٸ� �����Ѵ�
			if (maxCount < curCount) {
				maxCount = curCount;
				most_freq_num = cards[i - 1];
			}
			curCount = 1;
		}
	}

	// ������ ���ӵ� ���� �׷� ó��
	if (maxCount < curCount) {
		maxCount = curCount;
		most_freq_num = cards[N - 1];
	}

	cout << most_freq_num;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ī��

	/// ������ �̿��ؼ� �ð����⵵�� ũ�� ���� �� �ִ� ����

	// 1. counting sort�� Ǯ�⿡�� �迭�� ���̰� ������ �ȵȴ�.
	// 2. �� O(N^2)�� Ǯ�̸� ���ø��� ������? �ٺ���?

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}

	// Solution1();
	Solution2();

	return 0;
}
