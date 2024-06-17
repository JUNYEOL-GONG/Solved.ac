#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int res[10];

void Func(int curCount)
{
    if (curCount == M) {
        for (int i = 0; i < curCount; i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < N; i++) {
        // �� ������ �񳻸�����
        // ���̰� K�� ���� A�� A1 �� A2 �� ... �� AK-1 �� AK�� �����ϸ�, �񳻸������̶�� �Ѵ�.

        int n = arr[i];

        if (curCount > 0) {
            // ���� ��Ұ� �� ũ�ٸ� continue
            if (res[curCount - 1] > n)
                continue;
        }

        res[curCount] = n;
        Func(curCount + 1);
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : N�� M (8)

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    std::sort(arr, arr + N);

    Func(0);

    return 0;
}
