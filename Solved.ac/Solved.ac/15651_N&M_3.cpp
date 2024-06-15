#include <bits/stdc++.h>
using namespace std;

int N, M;
int answerArray[10];

void Func(int curCount)
{
    if (curCount == M) {
        for (int i = 0; i < curCount; i++) {
            cout << answerArray[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int number = 1; number <= N; number++) {
        answerArray[curCount] = number;
        Func(curCount + 1);
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : N�� M (3)

    // 1. 1���� N���� �ڿ��� �߿��� M���� �� ����
    
    // 2. ���� ���� ���� �� ��� �ȴ�.

    // 3. ������ ���� ������ �����ϴ� ������ ���

    cin >> N >> M;

    Func(0);

    return 0;
}
