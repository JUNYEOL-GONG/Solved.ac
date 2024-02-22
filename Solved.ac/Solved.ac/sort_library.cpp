#include <bits/stdc++.h>
using namespace std;

void SelectSort(vector<int>& arr, int n)
{
	// ���� ���� O(N^2)
	// ���� ���Ŀ� ���� ��������� ��ȯ(swap) Ƚ���� ����
	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i; j < n; ++j) {
			// �� �۾��� ���� ���¿� ������� ����� ����Ǵ� �ڵ��̴�
			if (arr[minIndex] > arr[j]) minIndex = j;
		}
		if (minIndex != i) swap(arr[minIndex], arr[i]);
	}
}

void BubbleSort(vector<int>& arr, int n)
{
	// ���� ���� O(N^2)
	// ���� ���ĵ� ���¶�� ���� ���� ���� ������
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			// ���� ���¿� ���� �ڵ� ������ ��ŵ�� �� �ִ�
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
}

void MergeSort(vector<int>& arr1, vector<int>& arr2, int n)
{
	// �ϳ��� ���ĵ� ����Ʈ�� ��ġ�� ���� ���� �˰����� �ٽ� �ܰ�
	// cf ) �װ� �׳� �ϳ��� ���Ĺ����� �ѹ��� ���� ���ķ� �Ѵٸ� O((N + M) ^ 2)
	// -> �Ʒ��� ���� ������� �Ѵٸ� O(N + M)���� �� �� �ִ� (���������� �ذ��� �����ϴ�)
	vector<int> arr12(n);
	int arr1Index = 0;
	int arr2Index = 0;
	int arr12Index = 0;
	while (arr12Index != n) {

		if (arr1Index >= arr1.size()) {
			arr12[arr12Index] = arr2[arr2Index++];
		}
		else if (arr2Index >= arr2.size()) {
			arr12[arr12Index] = arr1[arr1Index++];
		}
		else
		{
			if (arr1[arr1Index] >= arr2[arr2Index]) {		// >�� �ƴ� >=�� ���ش�. ������ �� ��������� Stable Sort ����
				arr12[arr12Index] = arr2[arr2Index++];
			}
			else {
				arr12[arr12Index] = arr1[arr1Index++];
			}
		}

		arr12Index++;
	}
}


int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	int n = 10;

	int thisCount = n / 2;
	int otherCount = n - thisCount;

	// �� ����Ʈ �����
	vector<int> arr1(thisCount);
	for (int i = 0; i < thisCount; ++i) {
		arr1[i] = rand();
	}
	vector<int> arr2(otherCount);
	for (int i = 0; i < thisCount; ++i) {
		arr1[i] = rand();
	}

	// ���ĵ� �� ����Ʈ
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());


	return 0;
}
