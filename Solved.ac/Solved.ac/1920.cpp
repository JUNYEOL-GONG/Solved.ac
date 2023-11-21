#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// <summary>
/// �̺� Ž�� (���̳ʸ� ��ġ)
/// </summary>
/// <param name="targetArr"></param>
/// <param name="value"></param>
/// <returns></returns>
bool binarySearch(std::vector<int>& targetArr, int value)
{
	int first = 0;
	int last = targetArr.size() - 1;
	int mid = (first + last) / 2;

	// �̺�Ž��
	// ������ ������ ������ "���"���� ���� �Ѵ�
	// �ٸ� ������δ� "���" �� "���"�Ѵ�.
	while (last > first)
	{
		// �߰� �ε������� ���ʿ� �ִ� ���
		if (value < targetArr[mid])
			last = mid - 1;
		// �߰� �ε������� �����ʿ� �ִ� ���
		else if (value > targetArr[mid])
			first = mid + 1;

		// mid index�� ���
		mid = (first + last) / 2;

		// ���� ��ġ�ϴ��� �Ǵ�
		if (value == targetArr[mid])
			return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// �� ã��

	int N; cin >> N;
	std::vector<int> arr(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	std::sort(arr.begin(), arr.end());

	int M; cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int value; cin >> value;

		// if (std::binary_search(arr.begin(), arr.end(), value))
		if (binarySearch(arr, value))
			printf("%d\n", true);
		else
			printf("%d\n", false);
	}

	return 0;
}