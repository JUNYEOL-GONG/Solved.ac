#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[10][10];

vector<pair<int, int>> cameraPositions;

vector<vector<int>> cameraDirs[6] = {
	{},
	{{0}, {1}, {2}, {3} },	// cctv1's cameraDir -> has each dir
	{{0, 2}, {1, 3}},
	{{0, 1}, {1, 2}, {2, 3}, {3, 0} },
	{{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
	{{0, 1, 2, 3}},
};

int minCount = 0;

// �� �� �� ��
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };

bool OutOfBound(int row, int col) {
	return row < 0 || row >= N || col < 0 || col >= M;
}

/// <summary>
/// �ٶ󺸴� �������� ��� ĭ�� �湮�Ѵ�
/// </summary>
vector<vector<bool>> Ray(int row, int col, int dir, vector<vector<bool>> detected)
{
	while (true) {
		row += dr[dir];
		col += dc[dir];
		if (OutOfBound(row, col)) break;
		if (board[row][col] == 6) break;
		detected[row][col] = true;
	}
	return detected;
}

/// <summary>
/// �簢������ ���� ����Ѵ�
/// </summary>
/// <param name="detected"></param>
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

	if (curCount == cameraPositions.size()) {
		Calc(detected);
		return;
	}

	int cameraPosRow = cameraPositions[curCount].first;
	int cameraPosCol = cameraPositions[curCount].second;

	int number = board[cameraPosRow][cameraPosCol];  // 1, 2, 3, 4, 5

	for (auto cameraDir : cameraDirs[number]) {
		vector<vector<bool>> tempDetected = detected;
		for (auto eachDir : cameraDir) {
			tempDetected = Ray(cameraPosRow, cameraPosCol, eachDir, tempDetected);
		}
		Func(curCount + 1, tempDetected);
	}

}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ����

	// TODO: ������ ������ Ǯ���
	// 4������ Ȱ���ؼ�,, <�� �� �� ��> �� 4������ ������ �����Ѵ�
	// ��� ����� ���� 4^ī�޶��
	// 2��, 5�� ī�޶�� ���� ���� ���� ����� ���� 4���� �ƴ� 2�� 1���ε�,
	// �� �κп� ���ؼ��� ���Ƿ� 4����� �صΰ� �ϰ� �����Ѵ�

	cin >> N >> M;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			cin >> board[row][col];
			if (board[row][col] == 6 || board[row][col] == 0) {
				minCount++; // cctv�� 0���� ��츦 ����ؼ� �ʱ�ȭ�Ѵ�
				continue;
			}
			cameraPositions.push_back({ row, col });
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
