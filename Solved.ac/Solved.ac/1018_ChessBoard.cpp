#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ü���� �ٽ� ĥ�ϱ�

	// Group : Brute Force �˰���

	int N, M;
	cin >> N >> M;

	std::vector<std::vector<char>> board(N);
	for (auto& vec : board)
		vec.resize(M);

	/// �ٽ� ����Ʈ..! (�Ӹ��� ���ƾ� ���� ��� ���Ѵ�..)
	std::string WB[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
	};

	std::string BW[8] = {
			"BWBWBWBW",
			"WBWBWBWB",
			"BWBWBWBW",
			"WBWBWBWB",
			"BWBWBWBW",
			"WBWBWBWB",
			"BWBWBWBW",
			"WBWBWBWB"
	};

	// ���� ����
	for (int i = 0; i < N; ++i)
	{
		// �� ���� ���°� �־�����.
		std::string inputString;
		cin >> inputString;
		for (int j = 0; j < inputString.length(); ++j)
		{
			char ch = inputString[j];
			if (ch == 'W')
				board[i][j] = 'W';
			else
				board[i][j] = 'B';
		}
	}

	// ���� 21�� 4õ��
	int resultMinCount = 0x7f7f7f7f;

	for (int a = 0; a <= N - 8; ++a)
	{
		for (int b = 0; b <= M - 8; ++b)
		{
			int rowStart = a;
			int columnStart = b;

			int wb_count = 0;
			int bw_count = 0;

			for (int i = rowStart; i < rowStart + 8; ++i)
			{
				for (int j = columnStart; j < columnStart + 8; ++j)
				{
					// WB�� ��
					if(board[i][j] != WB[i - rowStart][j - columnStart])
						wb_count++;

					// Bw�� ��
					if (board[i][j] != BW[i - rowStart][j - columnStart])
						bw_count++;
				}
			}

			int minCount = std::min(wb_count, bw_count);
			resultMinCount = std::min(resultMinCount, minCount);
		}
	}

	cout << resultMinCount << '\n';

	return 0;
}
