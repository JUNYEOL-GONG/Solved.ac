#include <bits/stdc++.h>
using namespace std;

int N;
int paper[2500][2500];
int cnt[3];

void Func(int ltx, int lty, int rbx, int rby)
{
    // bool���� ������� �ʰ� �Ϸ���, ���� ���� bool ���� ��ȯ�ϴ� �Լ��� ���� �� �ִ�.
    bool isAllSame = true;

    // ���� �ȿ� ��� ���ڰ� ������ Ȯ���Ѵ�
    int firstNumber = paper[ltx][lty];
    for (int i = ltx; i < rbx; i++) {
        for (int j = lty; j < rby; j++) {
            if (firstNumber != paper[i][j])
                isAllSame = false;
        }
    }

    // ���� ���� ��� ���ڰ� ���ٸ� �ش� ������ ������ �ø��� ��ȯ (���̻� �ɰ��� ����)
    if (isAllSame) {
        cnt[firstNumber + 1]++;
        return;
    }

    // ���̻� �ɰ����� �ʴ� ���̽� �����
    if (rbx - ltx < 3 || rby - lty < 3) return;

    // ���̸� 9��� �Ѵ�
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int ax = ltx + (rbx - ltx) / 3 * i;
            int ay = lty + (rby - lty) / 3 * j;
            int bx = ltx + (rbx - ltx) / 3 * (i + 1);
            int by = lty + (rby - lty) / 3 * (j + 1);
            Func(ax, ay, bx, by);
        }
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : ������ ����

    cin >> N;

    // paper
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> paper[row][col];
        }
    }

    Func(0, 0, N, N);

    for (int i = 0; i < 3; i++) {
        cout << cnt[i] << '\n';
    }

    return 0;
}
