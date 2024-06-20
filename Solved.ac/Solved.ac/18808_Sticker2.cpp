#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int R, C;
int sticker[15][15];
int origin[15][15];
int notebook[50][50];
int maxCount = 0;

bool CheckAttach(int mr, int mc)
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // ��ƼĿ�� ���� �� �ִ��� Ȯ���Ѵ�
            if (notebook[mr + i][mc + j] == 1 && sticker[i][j] == 1)
                return false;
        }
    }

    return true;
}

void DoAttach(int mr, int mc)
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // ��ƼĿ�� �κи� ���δ�
            if (sticker[i][j] == 1) {
                notebook[mr + i][mc + j] = 1;
            }
        }
    }
}

void Rotate(int rotatedCount)
{
    if (rotatedCount == 0) return;

    int temp[15][15];

    // copy
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            temp[i][j] = sticker[i][j];
        }
    }

    // rotate
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            sticker[j][R - 1 - i] = temp[i][j];
        }
    }

    // swap row and col
    std::swap(R, C);
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : ��ƼĿ ���̱�

    cin >> N >> M >> K;
    while (K--) {
        // ��ƼĿ�� ������� ���δ�
        cin >> R >> C;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> sticker[i][j];
                origin[i][j] = sticker[i][j];
            }
        }

        // TODO: �ּ��� ã�� ������ �ƴϴ�
        // �׳� ��Ȳ�� �Ǹ� ���̴� �׸��� �˰��� ���� ���̴�
        
        // ȸ��
        for (int rotatedCount = 0; rotatedCount < 4; rotatedCount++) {
            Rotate(rotatedCount);
            if (R > N || C > M) continue;
            // �̵�
            for (int moveRow = 0; moveRow < N; moveRow++) {
                for (int moveCol = 0; moveCol < M; moveCol++) {
                    if (moveRow + R > N || moveCol + C > M) continue;
                    // ��ƼĿ ���� �� �ִ� �� üũ
                    if (CheckAttach(moveRow, moveCol)) {
                        DoAttach(moveRow, moveCol);
                        goto end;
                    }
                }
            }
        }

        end:

        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                count += notebook[i][j];
            }
        }
        maxCount = std::max(maxCount, count);
    }

    cout << maxCount;

    return 0;
}
