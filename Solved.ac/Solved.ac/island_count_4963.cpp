#include "pch.h"

struct Pos
{
	int x, y;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> mapArray;

	// �� �� �� �� / �»� ��� ���� ����
	// (x,y) Pos �迭 ���
	vector<Pos> DirArray =
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
		int w, h;
		cout << "w�� h�� �Է��ϼ���" << '\n';
		cin >> w; cin >> h;
		cout << "=================" << '\n';

		// �Է��� ������ �ٿ��� 0�� �� �� �־�����.
		if (w == 0 && h == 0)
		{
			cout << "�Է��� ������ �ٿ��� 0�� �� �� �־�����" << '\n';
			break;
		}

		// w�� h�� 50���� �۰ų� ���� ���� ����
		if (w < 1 || w > 50 || h < 1 || h > 50)
		{
			cout << "w�� h�� 50���� �۰ų� ���� ���� ����" << '\n';
			break;
		}

		/*
		// ���� �ʱ�ȭ
		// ������ �� �� ���ƾ� �ؼ� CPU ĳ�� Ȱ�뿡�� �Ҹ��� ���� �ִ�.
		mapArray.resize(h);
		for (int i = 0; i < h; ++i)
		{
			mapArray[i].resize(w);
			for (int j = 0; j < w; ++j)
			{
				mapArray[i][j] = -1;
			}
		}
		*/

		// ȿ������ ���� �ʱ�ȭ
		mapArray.resize(h, std::vector<int>(w, 0));

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
		// -> ���� ������ �� ��δ� �ϳ��� ��
		for (int i = 0; i < h; ++i)			// ����
		{
			for (int j = 0; j < w; ++j)		// ����
			{
				// ��(1)�� ��츸 üũ�Ѵ� (�̹� �湮�� ���� x)
				if (mapArray[i][j] == 1)
				{
					// ��� ������ üũ����
					for (int k = 0; k < DirArray.size(); ++k)
					{
						// �ش� ���⿡ �ֳ�?
						if (mapArray[i - DirArray[k].y][j + DirArray[k].y])
						{

						}
					}
				}
			}
		}


		// �� �׽�Ʈ ���̽��� ���ؼ�, ���� ������ ����Ѵ�.
		int result = 0;
		cout << "-> ���� ���� : " << result << '\n';

		cout << "=================" << '\n';

	}


	return -1;
}