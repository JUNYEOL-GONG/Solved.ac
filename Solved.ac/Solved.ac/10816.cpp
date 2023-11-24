#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ���� ī�� 2

	/*
	 * // O(N^2)�� ����Ž�� - �ð� �ʰ�
	// ���
	int N; cin >> N;
	std::vector<int> numbers(N);
	for (int i = 0; i < N; ++i)
		cin >> numbers[i];

	// ��
	int M; cin >> M;
	std::vector<int> numbers2(M);
	std::vector<int> answers(M);

	for (int i = 0; i < M; ++i)
	{
		cin >> numbers2[i];
		for (int j = 0; j < N; ++j)
		{
			if (numbers[j] == numbers2[i])
				answers[i]++;
		}
	}

	for (const auto v : answers)
		cout << v << " ";
	*/

	/*
	 * // O(N + M)�� �ؽÿ� ����� Ž��
	// �ּ� : 0
	// �ִ� : 20000000
	int N; cin >> N;
	std::vector<int> numbers(20000001);
	for (int i = 0; i < N; ++i)
	{
		int value; cin >> value;
		numbers[value + 10000000]++;
	}
	int M; cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int value; cin >> value;
		cout << numbers[value + 10000000] << " ";
	}
	*/

	int N; cin >> N;
	std::unordered_map<int, int> uMap;
	for (int i = 0; i < N; ++i)
	{
		int value; cin >> value;
		uMap[value]++;
	}
	int M; cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int value; cin >> value;
		cout << uMap[value] << " ";
	}

	return 0;
}