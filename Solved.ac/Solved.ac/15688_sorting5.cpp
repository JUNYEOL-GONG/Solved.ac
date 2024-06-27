#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

int freq[2 * MAX + 1];

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : �� �����ϱ� 5

    /// Counting Sort�� ����ؼ� ������ �ذ��� ���� �ִ�.

    // �� ���������̶�?
    // 1 1 2 3 4 4 5 5 6 7 8 8 9 9 10

    // 1 <= N <= 1,000,000
    // -1,000,000 <= value <= 1,000,000

    // O(N)�� �ð����⵵�� freq[]�� ���� �߰��Ѵ�
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int value; cin >> value;
        freq[value + MAX]++;        // 5�� �Է¹޾�����, 1,000,000 + 5�� ������ 1����
    }

    // O(K)�� �ð����⵵�� K ������ ���� ���� ����� �����Ѵ�
    for (int value = 0; value <= 2 * MAX; value++) {
        if (freq[value] == 0) continue;
        /*
        for (int count = 0; count < freq[value]; count++) {
            cout << value - MAX << '\n';
        }
        */
        while (freq[value]--) {
            cout << value - MAX << '\n';
        }
    }

    // O(N+K)�� �ð����⵵�� ���� �˰���
    // ��, ���� ���� (K) �� �������� ������ ȿ�������� �����ϴ� �˰����̴�.
    // ������ ������ ũ�� ����� �� ����. �޸� ������

    return 0;
}
