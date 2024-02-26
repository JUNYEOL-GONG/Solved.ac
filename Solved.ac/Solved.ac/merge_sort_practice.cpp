#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };
int tmp[1000001] = {};

// 1. Stable Sort�� ������ ������ �ִ�
// �� ������ ������Ű����
// �� ����Ʈ���� ���� ���� ���ҿ� �� ����Ʈ���� ���� ���� ������ �켱������ ���� ��
// �� ����Ʈ�� ���Ҹ� ���� �����ִ� �۾��� merge sort���� �ڿ������� �ߴ� (���ʺ��� ��������� ���ư���)
void merge(int st, int en)
{
	int mid = (st + en) / 2;
	int leftIndex = st;
	int rightIndex = mid;
	for (int i = st; i < en; ++i)
	{
		// leftIndex�� ���� ���
		if (leftIndex >= mid) tmp[i] = arr[rightIndex++];
		// rightIndex�� ���� ���
		else if (rightIndex >= en) tmp[i] = arr[leftIndex++];
		// left�� ���� right�� �� ���� ���� ���
		else if (arr[leftIndex] < arr[rightIndex]) tmp[i] = arr[leftIndex++];
		else tmp[i] = arr[rightIndex++];
	}
	for (int i = st; i < en; ++i)
	{
		arr[i] = tmp[i];
	}
}

void merge_sort(int st, int en)
{
	if (st + 1 == en) return;
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	merge_sort(0, n);

	for (int i = 0; i < n; i++) cout << arr[i] << ' ';  // -53 3 12 15 16 22 23 25 46 357

	return 0;
}
