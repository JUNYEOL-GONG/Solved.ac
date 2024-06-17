#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[10];
int res[10];
void Func(int curCount) {
	if (curCount == M) {
		for (int i = 0; i < curCount; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int temp = -1;
	for (int i = 0; i < N; i++) {
		if (temp == arr[i]) continue;
        // 7 1 / 9 1 / 9 7 �� ���� ������ ��ŵ�Ѵ�
        if (curCount > 0) {
            if (arr[i] < res[curCount - 1])
                continue;
        }
		temp = arr[i];					/// ** ���� ���̿��� ���� ���ڿ� �ߺ��Ǵ� ���� �������� �ϸ� �ߺ��Ǵ� ������ ��������� ������ X
		res[curCount] = arr[i];
		Func(curCount + 1);
	}
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : N�� M (12)

    // 1. �� ������ �񳻸������̾�� �Ѵ�.
    // => ���̰� K�� ���� A�� A1 �� A2 �� ... �� AK - 1 �� AK�� �����ϸ�, �񳻸������̶�� �Ѵ�.

    // 2. ���� ���� ���� �� ��� �ȴ�.

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    std::sort(arr, arr + N);
    Func(0);

    return 0;
}
