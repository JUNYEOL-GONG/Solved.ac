#include <bits/stdc++.h>
using namespace std;

int length;
int box[100000];        // length�� �ִ� 100000��
int target;
int sequence[2000001];  // target�� �ִ� 1000000

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : �� ���� ��

    cin >> length;
    for (int index = 0; index < length; ++index) {
        cin >> box[index];
    }
    cin >> target;

    int cnt = 0;

    /*
    // O(N^2)
    // n : 100000�ε�
    // O(N^2)���� �̹� 100���� �Ѿ
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (box[i] + box[j] == x)
                cnt++;
        }
    }
    */

    // x = ai + aj

    // O(N)
    /// Baaaarking Dog ������ Ǭ�Ŷ� ���� ����
    /// ��¥ �ű��ϴ�.. �˰����� �����..
    for (int index = 0; index < length; ++index) {
        int opposite = target - box[index];
        if (opposite < 0)   // index�� ������ ������ ��� ����ó��
            continue;
        if (sequence[opposite] == 1)
            cnt++;
        else
            sequence[box[index]] = 1;
    }

    cout << cnt;

    return 0;
}
