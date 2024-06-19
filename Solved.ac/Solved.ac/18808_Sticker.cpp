#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<vector<int>> stickers[105];

int maxCount = -1000000000;

// vector<vector<int>> notebook�� 90�� ȸ����Ű�� �Լ�
vector<vector<int>> RotateSticker(int dir, vector<vector<int>> sticker) {     // dir: 0, 1, 2, 3 -> 4���� ȸ��
    if (dir == 0) return sticker;
    for (int i = 0; i < sticker.size(); i++) {
        for (int j = 0; j < sticker[i].size(); j++) {

        }
    }
    return sticker;
}

void Recursive(int curCount, vector<vector<int>> notebook) {
    if (curCount == K) {
        int count = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                if (notebook[i][j] == 1) {
                    count++;
                }
            }
        }
        maxCount = std::max(maxCount, count);
        return;
    }

    // notebook�� ��ƼĿ�� ������ (�پ��� ����� �� ����)
    for (int number = curCount; number < K; number++) {

        // 1�� ��ƼĿ�� ��� ��Ʈ�Ͽ� ���� �� �ִ� ����� ���� Ž���Ѵ�
        // ���� ����� �ֿ켱�����ϰ�, ȸ���� �����ϴ�
        // ���� ��ƼĿ�� �̵���Ű�� ȸ����Ű�� ����� �����ؾ� �Ѵ�.

        // ȸ�� (0��, 90��, 180��, 270�� - �ð� ����)
        for (int rotatedNumber = 0; rotatedNumber < 4; rotatedNumber++) {
            auto sticker = stickers[curCount];
            vector<vector<int>> tempSticker = sticker;
            tempSticker = RotateSticker(rotatedNumber, tempSticker);
            // �̵� (������ �켱, ������ �� ����)
            for (int row = 0; row < N; row++) {                 // row = 0 : ���� row = N : �Ʒ���
                for (int col = 0; col < M; col++) {             // col = 0 : ���� col = M : ������
                    // ������ ����� ��쿡 ��ŵ
                    int stickerRowSize = sticker.size();
                    int stickerColSize = sticker[0].size();
                    if (row + stickerRowSize >= N || col + stickerColSize >= M) continue;
                    // ��ƼĿ�� ��Ʈ�Ͽ� ����
                    vector<vector<int>> tempNotebook = notebook;
                    for (int r = 0; r < stickerRowSize; r++) {
                        for (int c = 0; c < stickerColSize; c++) {
                            tempNotebook[row + r][col + c] = sticker[r][c];
                        }
                    }
                    Recursive(curCount + 1, tempNotebook);
                }
            }
        }
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : ��ƼĿ ���̱�

    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int R, C; cin >> R >> C;
        stickers[i].resize(R);
        for (int row = 0; row < R; row++) {
            stickers[i][row].resize(C);
            for (int col = 0; col < C; col++) {
                cin >> stickers[i][row][col];
            }
        }
    }

    vector<vector<int>> notebook(N, vector<int>(M, 0));
    Recursive(0, notebook);

    cout << maxCount;

    return 0;
}
