#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int res[10];
int isUsed[10];

void Func(int curCount) {

	if (curCount == M) {
		for (int i = 0; i < curCount; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	int temp = 0;
	for (int i = 0; i < N; i++) {
		if (isUsed[i]) continue;
		if (temp == arr[i]) continue;	/// ** �ٸ� index������ ���� ���� �ߺ��Ǵ� ��� ��ŵ
		res[curCount] = arr[i];
		temp = arr[i];
		isUsed[i] = true;
		Func(curCount + 1);
		isUsed[i] = false;
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : N�� M (9)

	// ���� ���� �Էµ� �� �ִ�

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	std::sort(arr, arr + N);
	Func(0);

	return 0;
}
