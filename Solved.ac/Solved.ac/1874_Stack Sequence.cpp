#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ���� ����

	int n; cin >> n;

	// Stack���� ���� �����
	// 4 3 6 8 7 5 2 1

	std::string result;

	// ���⼭ ť�� ���� �Է��� ������� ������ ���� ����� �ڷᱸ��
	std::queue<int> myQueue;
	for (int i = 0; i < n; ++i)
	{
		int value; cin >> value;
		myQueue.push(value);
	}

	// ���� ������ �����ϱ� ���� ����� �ڷᱸ��
	std::stack<int> myStack;
	for (int value = 1; value <= n; ++value)
	{
		// �켱 ������������ ���ÿ� ���� �ִ´�
		myStack.push(value);
		result += '+';
		result += '\n';

		// ����(������ ����� ����)�� ť(������ ��)�� ������� �����鼭 ����� ���� ��ġ�ؾ���
		while(!myStack.empty() && !myQueue.empty() && (myStack.top() == myQueue.front()))
		{
			myStack.pop();
			myQueue.pop();
			result += '-';
			result += '\n';
		}
	}

	// ���� �ڷᱸ���� �־��� ������ ������ ���ߴٴ� �ǹ�
	if (!myQueue.empty())
		cout << "NO" << '\n';
	else
		cout << result;

	return 0;
}
