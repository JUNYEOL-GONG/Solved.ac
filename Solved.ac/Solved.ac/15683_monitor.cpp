#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[10][10] = {};

typedef pair<int, int> Pos;
typedef pair<int, int> CameraInfo;
vector<pair<CameraInfo, Pos>> cameras;

int minCount = 1000000000;

// ���� ����: �������� �ٶ󺸰� �ִٰ� �����Ѵ�.

// �ý����� ������ �Ѵ�.
// CCTV�� Ư�� ������ ������ ���� ��, �� �� �ִ� �������� ��� Ž���� �� �ִ�.. ����

vector<vector<bool>> CCTV1(CameraInfo& info, Pos pos, vector<vector<bool>> detected) {

    if (info.second > 4)
        return detected;

    if (info.second == 1) {
        // 1. ������ �������� ���
        int row = pos.first;
        int col = pos.second;
        // ���� �ε����ų� ������ ����������
        while (true) {
            col += 1;
            if (row < 0 || row >= N || col < 0 || col >= M) break;
            if (board[row][col] == 6) break;
            detected[row][col] = true;
        }
    }
    else if (info.second == 2) {
        // 2. ���� �������� ���
        int row = pos.first;
        int col = pos.second;
        // ���� �ε����ų� ������ ����������
        while (true) {
            row -= 1;
            if (row < 0 || row >= N || col < 0 || col >= M) break;
            if (board[row][col] == 6) break;
            detected[row][col] = true;
        }
    }
    else if (info.second == 3) {
        // 3. ���� �������� ���
        int row = pos.first;
        int col = pos.second;
        // ���� �ε����ų� ������ ����������
        while (true) {
            col -= 1;
            if (row < 0 || row >= N || col < 0 || col >= M) break;
            if (board[row][col] == 6) break;
            detected[row][col] = true;
        }
    }
    else if (info.second == 4) {
        // 4. �Ʒ��� �������� ���
        int row = pos.first;
        int col = pos.second;
        // ���� �ε����ų� ������ ����������
        while (true) {
            row += 1;
            if (row < 0 || row >= N || col < 0 || col >= M) break;
            if (board[row][col] == 6) break;
            detected[row][col] = true;
        }
    }

    info.second++;
    return detected;
}

vector<vector<bool>> CCTV2(CameraInfo& info, Pos pos, vector<vector<bool>> detected)
{
    if (info.second > 2)
        return detected;

    if (info.second == 1) {
        // 1. �����ʰ� ���� �������� ���
        int row_1 = pos.first;
        int col_1 = pos.second;
        // ���� �ε����ų� ������ ����������
        while (true) {
            if (row_1 < 0 || row_1 >= N || col_1 < 0 || col_1 >= N) break;
            if (board[row_1][col_1] == 6) break;
            detected[row_1][++col_1] = true;
        }
        int row_2 = pos.first;
        int col_2 = pos.second;
        // ���� �ε����ų� ������ ����������
        while (true) {
            if (row_2 < 0 || row_2 >= N || col_2 < 0 || col_2 >= N) break;
            if (board[row_2][col_2] == 6) break;
            detected[row_2][++col_2] = true;
        }
    }
    else if (info.second == 2) {
        // 2. ���ʰ� �Ʒ��� �������� ���
    }

    info.second++;
    return detected;
}

vector<vector<bool>> CCTV3(CameraInfo& info, Pos pos, vector<vector<bool>> detected)
{
    if (info.second > 4)
        return detected;

    if (info.second == 1) {
        // 1. �����ʰ� ���� �������� ���
    }
    else if (info.second == 2) {
        // 2. ���ʰ� ���� �������� ���
    }
    else if (info.second == 3) {
        // 3. ���ʰ� �Ʒ��� �������� ���
    }
    else if (info.second == 4) {
        // 4. �Ʒ��ʰ� ������ �������� ���
    }

    info.second++;
    return detected;
}

vector<vector<bool>> CCTV4(CameraInfo& info, Pos pos, vector<vector<bool>> detected)
{
    if (info.second > 4)
        return detected;

    if (info.second == 1) {
        // 1. �����ʰ� ���ʰ� ���� �������� ���
    }
    else if (info.second == 2) {
        // 2. ���ʰ� ���ʰ� �Ʒ��� �������� ���
    }
    else if (info.second == 3) {
        // 3. ���ʰ� �Ʒ��ʰ� ������ �������� ���
    }
    else if (info.second == 4) {
        // 4. �Ʒ��ʰ� �����ʰ� ���� �������� ���
    }

    info.second++;
    return detected;
}

vector<vector<bool>> CCTV5(CameraInfo& info, Pos pos, vector<vector<bool>> detected)
{
    if (info.second > 1)
        return detected;

    if (info.second == 1) {
        // 1. ������ ���� ���� �Ʒ��� �������� ���
    }

    info.second++;
    return detected;
}

void Calc(vector<vector<bool>> detected) {
    int count = 0;
    // �簢���븦 ���Ѵ�
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0 && detected[i][j] == false) {
                count++;
            }
        }
    }
    minCount = std::min(minCount, count);
}

void Func(int curCount, vector<vector<bool>> detected) {
    // base condition
    if (curCount == cameras.size()) {
        Calc(detected);
        return;
    }

    for (int i = 0; i < cameras.size(); i++) {
        auto camera = cameras[i];
        auto cameraNumber = camera.first.first;
        switch (cameraNumber) {
        case 1:
            detected = CCTV1(camera.first, camera.second, detected);
            break;
        case 2:
            detected = CCTV2(camera.first, camera.second, detected);
            break;
        case 3:
            detected = CCTV3(camera.first, camera.second, detected);
            break;
        case 4:
            detected = CCTV4(camera.first, camera.second, detected);
            break;
        case 5:
            detected = CCTV5(camera.first, camera.second, detected);
            break;
        }
        Func(curCount + 1, detected);
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : ����

    cin >> N >> M;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> board[row][col];
            if (board[row][col] == 6 || board[row][col] == 0) continue;
            cameras.push_back({ {board[row][col], 1}, {row, col} });
        }
    }

    vector<vector<bool>> detected(10);
    for (int i = 0; i < 10; i++) {
        detected[i].resize(10);
    }

    Func(0, detected);

    cout << minCount;

    return 0;
}
