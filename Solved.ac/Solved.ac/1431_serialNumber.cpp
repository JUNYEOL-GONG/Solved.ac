#include <bits/stdc++.h>
using namespace std;

int N;
string serialNumbers[55];

/// <summary>
/// compare �Լ��� �� ���� a�� b�� �޾Ƽ� '��� ���� �տ� �;� �ϴ���' �����մϴ�.
/// �������� ������ ���(ū ���� ���ʿ� �;��ϴ� ���), a > b�� ��� true�� ��ȯ�Ͽ� a�� b���� �տ� ������ �մϴ�.
/// ���� �Լ��� ���� �� compare �Լ��� ȣ���Ͽ� ��� ��Ҹ� �����մϴ�.
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
bool cmp(const string& a, const string& b) {

	// �迭�� ���� �̸� ����
	int aLength = a.length();
	int bLength = b.length();

	// ���� 1: A�� B�� ���̰� �ٸ���, ª�� ���� ���� �´�.
	if (aLength != bLength)
		return aLength < bLength;		// ª�� �� ���ʿ� ��ġ�ؾ� �Ѵٴ� ��
	else {
		// ���� 2
		// : A�� ��� �ڸ����� �հ� B�� ��� �ڸ����� ���� ���ؼ�
		// ���� ���� ������ ���� �����´�. (������ �͸� ���Ѵ�)
		int aSum = 0, bSum = 0;
		for (int i = 0; i < aLength; i++) {
			if (isdigit(a[i])) {		// ���ڷ� ��ȯ������ ������ ������ �������� ���ع����� (0�� 48�� ���ع���)
				aSum += a[i] - '0';
			}
		}
		for (int i = 0; i < bLength; i++) {
			if (isdigit(b[i])) {
				bSum += b[i] - '0';
			}
		}
		if (aSum != bSum)
			return aSum < bSum;			// ���� ���� �� ���ʿ� ��ġ�ؾ� �Ѵٴ� ��
		// ���� 3: ���������� ���Ѵ�. ���ڰ� ���ĺ����� ���������� �۴�.
		else {
			int minLength = aLength < bLength ? aLength : bLength;
			for (int i = 0; i < minLength; i++) {
				if (a[i] != b[i]) {
					return a[i] < b[i];	// ���������� ���� �� ���ʿ� ��ġ�ؾ� �Ѵٴ� ��
				}
			}
			return a[0] < b[0];
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : �ø��� ��ȣ

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> serialNumbers[i];
	}

	std::sort(serialNumbers, serialNumbers + N, cmp);

	for (int i = 0; i < N; i++) {
		cout << serialNumbers[i] << '\n';
	}

	return 0;
}
