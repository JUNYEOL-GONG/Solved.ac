#include <bits/stdc++.h>
using namespace std;

int N, M;
bool isUsed[10];
int answerArray[10];

void Func(int curCount)
{
    // 1���� N���� �ڿ��� �߿��� '�ߺ� ����' M���� �� ����
    // �� ������ ���������̾�� �Ѵ�.

    // M���� �迭�� ����Ѵ�
    if (curCount == M)
    {
        // �迭�� ���ϴ� ������ ��Ұ� �� ��, �ѹ��� ����Ѵ�
        for (int i = 0; i < curCount; i++) {
            cout << answerArray[i] << ' ';
        }

        cout << '\n';

        return;
    }

    for (int number = 1; number <= N; number++) {

        // �̹� ���� ���̸� ��ŵ
        if (isUsed[number]) continue;

        // �̹� 1���� �����ϴ� ��쿡 ���� �߰��Ϸ��� ���� �� ū�� Ȯ���Ѵ�
        if (curCount > 0) {
            if (answerArray[curCount - 1] > number)
                continue;
        }

        answerArray[curCount] = number;

        isUsed[number] = true;
        Func(curCount + 1);
        isUsed[number] = false;
    }
}

void Func2(int curCount, int startNumber)
{
    if (curCount == M)
    {
        // �迭�� ���ϴ� ������ ��Ұ� �� ��, �ѹ��� ����Ѵ�
        for (int i = 0; i < curCount; i++) {
            cout << answerArray[i] << ' ';
        }

        cout << '\n';

        return;
    }

    for (int number = startNumber; number <= N; number++) {
        answerArray[curCount] = number;
        Func2(curCount + 1, number + 1);        // ���� ���� �� �� ���� ������ ū ������ �����ϵ��� �߽��ϴ�. (�������� �ذ�)
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : N�� M (2)

    cin >> N >> M;

    // Func(0);
    Func2(0, 1);

    return 0;
}
