#include <bits/stdc++.h>

int n = 10;
int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };

using namespace std;

// merge_sort ó�� ��������� �����Ǵ� ����
// �� �۾����� pivot�� ���ڸ��� ������ �Ѵ�
void quick_sort(int st, int en) // arr[st::en]�� �����Ѵ�
{
	if (st + 1 >= en) return;

	int pivot = st;
	int left = st + 1;
	int right = en - 1;

	while (true)
	{
		while (arr[pivot] >= arr[left] && left <= right) left++;
		while (arr[pivot] < arr[right] && left <= right) right--;

		if (left > right) break;

		swap(arr[left], arr[right]);
	}

	swap(arr[pivot], arr[right]);
	swap(pivot, right);

	quick_sort(st, pivot);
	quick_sort(pivot + 1, en);
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	quick_sort(0, n);

	for (int i = 0; i < n; i++) cout << arr[i] << ' ';

	return 0;
}
