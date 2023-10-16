#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Pos
{
	int x, y;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// �� / �� / �� / �� / �»� / ��� / ���� / ����
	const vector<Pos> DirArray =
	{
		{0, 1},
		{0, -1},
		{-1, 0},
		{1, 0},
		{-1, 1},
		{1, 1},
		{-1, -1},
		{1, -1}
	};

	// �Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�
	while (true)
	{
		// �� �׽�Ʈ ���̽��� ù° �ٿ��� ������ �ʺ� w�� ���� h�� �־�����.
		int w; cin >> w;
		int h; cin >> h;

		// �Է��� ������ �ٿ��� 0�� �� �� �־�����.
		if (w == 0 && h == 0) break;
		// w�� h�� 50���� �۰ų� ���� ���� ����
		if (w < 1 || w > 50 || h < 1 || h > 50) break;

		// ȿ������ ���� �ʱ�ȭ
		vector<vector<int>> mapArray;
		mapArray.resize(h, std::vector<int>(w, 0));

		int islandCnt = 0;

		// ������ �׸���
		for (int i = 0; i < h; ++i)			// ����
		{
			for (int j = 0; j < w; ++j)		// ����
			{
				// 1�� ��, 0�� �ٴ�
				int mapInfo; cin >> mapInfo;
				mapArray[i][j] = mapInfo;
			}
		}

		// ���� ������ ���Ѵ�
		// -> ���� ���� ������ �� ��δ� �ϳ��� ��
		for (int i = 0; i < h; ++i)	// ����
		{
			for (int j = 0; j < w; ++j)	// ����
			{
				// ���� ���� �ϳ� ������ �� ���� �������� Ž���� �����Ѵ� ==> "������"
				if (mapArray[i][j] == 1)
				{
					// ó�� �� Ž�� ���� ���� curPos�� �ΰ� �����Ѵ�
					Pos curPos = { j,i };

					// ������ ���� map���� ����Ѵ�
					mapArray[curPos.y][curPos.x] = -1;

					// �Դ����� ���ư��� ���ؼ� ������ ���� ����Ѵ�.
					stack<Pos> posStack;
					posStack.push(curPos);

					// ���� ������ �̾������� üũ
					while(true)
					{
						bool isFind = false;

						// ��� ������ üũ����
						for (int k = 0; k < DirArray.size(); ++k)
						{
							// Ž���Ϸ��°��� ������ ����� �ʴ��� üũ
							if (curPos.y - DirArray[k].y >= 0 &&
								curPos.x + DirArray[k].x >= 0 &&
								curPos.y - DirArray[k].y < h &&
								curPos.x + DirArray[k].x < w)
							{
								// �ش� ���⿡ �ֳ�?
								if (mapArray[curPos.y - DirArray[k].y][curPos.x + DirArray[k].x] == 1)
								{
									// ���� ��ġ�� �̵�
									curPos = { curPos.x + DirArray[k].x , curPos.y - DirArray[k].y };

									// �̵��� ��ġ�� ���ÿ� �ִ´�
									posStack.push(curPos);

									// ������ ���� map���� ����Ѵ�
									mapArray[curPos.y][curPos.x] = -1;

									isFind = true;

									break;
								}
							}
						}

						// �� ã�ƺôµ��� ����..?
						if (!isFind)
						{
							// �� Ž�� ����
							if (posStack.empty())
							{
								islandCnt++;
								break;
							}

							// �ڷ� ���ư���
							posStack.pop();

							if (!posStack.empty())
								curPos = posStack.top();
						}
					}
				}
			}
		}

		// �� �׽�Ʈ ���̽��� ���ؼ�, ���� ������ ����Ѵ�.
		cout << islandCnt << '\n';
	}

	return 0;
}