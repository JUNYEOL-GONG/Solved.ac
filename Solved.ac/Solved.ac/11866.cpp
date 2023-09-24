#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	int K; cin >> K;

	// �似Ǫ���� ����
	// (N, K) - �似Ǫ�� ����

	vector<int> arr(N, 0);
	int cnt = N;

	// �ʱ�ȭ
	for (int i = 0; i < N; ++i)
		arr[i] = i + 1;

	int index = 0;

	// ����� �� ������ ������ ��� ����
	while (cnt > 0)
	{
		if (K > cnt)
			K %= cnt;

		index += K;

		cout << arr.at(index - 1) << endl;
		arr.erase(arr.begin() + index - 1);

		cnt--;
	}

	return 0;
}