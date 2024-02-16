#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : �� ����

    // N : ���п��࿡ �����ϴ� �л� ���� ��Ÿ���� ����
    // K : �� �濡 ������ �� �ִ� �ִ� �ο� ��
    // S : ����
    // Y : �г�
    int N; int K;
    cin >> N >> K;

    // 2���� �迭�� �̿��Ѵ�
    int arr[7][2] = {};
    for (int i = 0; i < N; i++) {
        int S, Y;
        cin >> S >> Y;
        arr[Y][S]++;
    }

    int roomCount = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < 2; j++) {
            if (arr[i][j] == 0)
                continue;
           roomCount += arr[i][j] / K;
           if (arr[i][j] % K != 0)      // ** �߰��� �����ִ� ����.. **
               roomCount++;
        }
    }

    cout << roomCount;

    return 0;
}
