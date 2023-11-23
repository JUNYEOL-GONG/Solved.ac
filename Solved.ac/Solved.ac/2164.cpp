#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <chrono>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ī�� 2

	int N; cin >> N;

	std::queue<int> myQueue;
	bool isTrash = true;

	// �ڵ� ���� ���� ����
	auto start = std::chrono::high_resolution_clock::now();

	// ī�� ����
	for (int i = 1; i <= N; ++i)
	{
		myQueue.push(i);
	}

	// ���� ����
	while (myQueue.size() != 1)
	{
		// 1. ������ �ְ� �ϴ� �۾��� �ݺ�
		myQueue.pop();
		myQueue.push(myQueue.front());
		myQueue.pop();

		/*
		// ��� 2. �οﰪ�� ���� ������ �ְ� �۾��Ѵ�
		// ������ ���
		if (isTrash)
		{
			myQueue.pop();
			isTrash = false;
		}
		// �Ʒ��� �ִ� ���
		else
		{
			myQueue.push(myQueue.front());
			myQueue.pop();
			isTrash = true;
		}
		*/
	}

	cout << myQueue.front() << '\n';

	// �ڵ� ���� ���� ��
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;

	std::cout << "���� �ð�: " << duration.count() << " ��" << std::endl;

	return 0;
}