// �Ｚ SW �����׽�Ʈ A�� ���� ����
// �ùķ��̼�

#include <bits/stdc++.h>
using namespace std;

int N, M;
int maps[10][10];
int firstMaps[10][10];
int normalAreaCount = 0x7F7F7F7F; // 2,130,706,431

class myVector
{
public:
	int x, y;

	myVector() = default;
	myVector(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

class cctv
{
public:
	int number;
	int excuteCount;

	cctv(int n, int cnt)
	{
		this->number = n;
		this->excuteCount = cnt;
	}
};

void print_map()
{
	cout << "=============================" << '\n';

	// i�� ���� ����, �� y���� ��Ÿ����
	for (int i = 0; i < N; ++i)
	{
		// j�� ���� ����,  �� x���� ��Ÿ����
		for (int j = 0; j < M; ++j)
		{
			// maps[y��][x��]�� ����
			// ������ x���̰� �������� y���� ��ī��Ʈ ��ǥ�谡 �����ȴ�
			cout << maps[i][j] << ' ';
		}

		cout << '\n';
	}
}

int check_areaCount()
{
	// �ʱ�ȭ
	int cnt = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (maps[i][j] == 0) cnt++;
		}
	}

	return cnt;
}

void reset_map()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			maps[i][j] = firstMaps[i][j];
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ����

	// �繫���� ũ��� ����,
	// CCTV�� ������ �־����� ��,
	// CCTV�� ������ ������ ���ؼ�,
	//
	// �簢 ������ �ּ� ũ�⸦ ���ϴ� ���α׷��� �ۼ�

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int input; cin >> input;

			firstMaps[i][j] = input;
			maps[i][j] = input;
		}
	}

	// �ִ��� CCTV�� �� ��ġ�ؼ� ���� ������ ������ �� �־�� �簢 ������ ���� �ּҰ� �ȴ�

	/// CCTV�� ���� ����

	myVector cctvBasic[4] = { {0, 1}, {0, -1}, {-1, 0}, {1 ,0} };

	// 1. ���� ���� (�� / �� / �� / ��)
	myVector cctv1[4][1] = { cctvBasic[0], cctvBasic[1], cctvBasic[2], cctvBasic[3] };
	// 2. ���� ���� (�� + �� / �� + ��)
	myVector cctv2[2][2] = { {cctvBasic[0], cctvBasic[1]}, {cctvBasic[2], cctvBasic[3]} };
	// 3. ���� ���� (�� + �� / �� + �� / �� + �� / �� + ��)
	myVector cctv3[4][2] = { {cctvBasic[0], cctvBasic[3]}, {cctvBasic[0], cctvBasic[2]}, {cctvBasic[1], cctvBasic[3]}, {cctvBasic[1], cctvBasic[2]} };
	// 4. �� ���� (�� + �� + �� / �� + �� + �� / �� + �� + �� / �� + �� + ��)
	myVector cctv4[4][3] = { {cctvBasic[0], cctvBasic[2], cctvBasic[3]}, {cctvBasic[0], cctvBasic[3], cctvBasic[1]}, {cctvBasic[3], cctvBasic[1], cctvBasic[2]}, {cctvBasic[1], cctvBasic[2], cctvBasic[0]} };
	// 5. �� ���� (�� + �� + �� + ��)
	myVector cctv5[1][4] = { {cctvBasic[0], cctvBasic[1], cctvBasic[2], cctvBasic[3]} };

	int cctvRayCount[5] = { 1,2,2,3,4 };
	int cctvExcuteCount[5] = { 4,2,4,4,1 };

	vector<pair<cctv, myVector>> cctvInfo;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (maps[i][j] >= 1 && maps[i][j] <= 5)
			{
				int cctvNumber = maps[i][j];
				cctv cctv(cctvNumber, cctvExcuteCount[cctvNumber - 1]);
				myVector cctvPosition(j, i);
				cctvInfo.emplace_back(cctv, cctvPosition);
			}
		}
	}

	// N�� for���� ������ �Ѵ�

	while (true)
	{
		// cctv�� �ϳ��� ����
		for (int i = 0; i < cctvInfo.size(); ++i)
		{
			const auto this_cctv = cctvInfo[i];
			myVector curPos = { this_cctv.second.x, this_cctv.second.y };

			// cctv ������ ����
			for (int c = 0; c < cctvRayCount[this_cctv.first.number - 1]; ++c)
			{
				// cctv�� ������ �� ���
				while (true)
				{
					myVector nextPos = { 0,0 };

					// �� ����
					if (this_cctv.first.number == 1)
						nextPos = { curPos.x + cctv1[this_cctv.first.excuteCount - 1][c].x, curPos.y + cctv1[this_cctv.first.excuteCount - 1][c].y };
					// �� ����
					else if (this_cctv.first.number == 2)
						nextPos = { curPos.x + cctv2[this_cctv.first.excuteCount - 1][c].x, curPos.y + cctv2[this_cctv.first.excuteCount - 1][c].y };
					// �� ����
					else if (this_cctv.first.number == 3)
						nextPos = { curPos.x + cctv3[this_cctv.first.excuteCount - 1][c].x, curPos.y + cctv3[this_cctv.first.excuteCount - 1][c].y };
					// �� ����
					else if (this_cctv.first.number == 4)
						nextPos = { curPos.x + cctv4[this_cctv.first.excuteCount - 1][c].x, curPos.y + cctv4[this_cctv.first.excuteCount - 1][c].y };
					// �� ����
					else if (this_cctv.first.number == 5)
						nextPos = { curPos.x + cctv5[this_cctv.first.excuteCount - 1][c].x, curPos.y + cctv5[this_cctv.first.excuteCount - 1][c].y };

					if (nextPos.x < 0 || nextPos.x >= M || nextPos.y < 0 || nextPos.y >= N) break;
					if (maps[nextPos.y][nextPos.x] == 6) break;

					curPos = nextPos;

					if (maps[nextPos.y][nextPos.x] >= 1 && maps[nextPos.y][nextPos.x] <= 5) continue;

					maps[curPos.y][curPos.x] = 7;
				}
			}
		}

		// �� ����Ŭ ���� ������ �� üũ�Ѵ�
		normalAreaCount = min(check_areaCount(), normalAreaCount);
		reset_map();
	}

	cout << normalAreaCount << '\n';

	return 0;
}
