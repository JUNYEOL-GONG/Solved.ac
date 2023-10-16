#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int k; cin >> k;
	int cnt = 0;

	vector<int> arr(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	// ��ǥ K��
	// �迭 �ڿ��� ���� ����
	// ���� ������ ����ؼ� ����� �� �ִ�.

	for (int i = n; i > 0; --i)
	{
		while(k - arr[i] >= 0)
		{
			k -= arr[i];
			cnt++;
		}

		if (k == 0)
			break;
	}

	cout << cnt << endl;

	return 0;
}