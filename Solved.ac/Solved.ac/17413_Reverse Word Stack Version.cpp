#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;

std::string GetStringFromStack(std::stack<char>& myStack)
{
	std::string tempString;

	// ���ÿ� �ִ� ��� ���ڸ� ������ (������ ���ڿ�)
	while (!myStack.empty())
	{
		tempString += myStack.top();
		myStack.pop();
	}

	return tempString;
}

std::string ReverseString(std::string inputString)
{
	size_t length = inputString.length();
	for (int i = 0; i < length / 2; ++i)
		std::swap(inputString[i], inputString[length - 1 - i]);

	return inputString;
}

std::string Solution(const std::string& inputString)
{
	const size_t length = inputString.length();
	std::string resultString;
	bool isTag = false;

	// �ϳ��� ���ÿ��� ���ڵ��� �ְ� ���� �����Ѵ�
	std::stack<char> myStack;

	// inputString�� ��� �д´�
	for (size_t i = 0; i < length; ++i)
	{
		// �ϳ��� ����
		char ch = inputString[i];

		// �ܾ��� ���
		if (!isTag)
		{
			// ' '�� �ƴ� �ٸ� ���ڶ�� ���ÿ� �ִ´�
			if (ch != ' ')
			{
				// '<'�� ���´ٸ� �ܾ��� ��. �׸��� ������ �±װ� ���´ٴ� ��
				if (ch == '<')
				{
					isTag = true;

					// '<'�� ù ���ڿ��� ���� �� �ƴ϶�� �ܾ��� ���Ḧ ����
					if (i != 0)
						resultString += GetStringFromStack(myStack);
				}

				myStack.push(ch);
			}
			// ' '�� ���´ٸ� �ܾ��� ��. �׸��� ������ �ܾ �Ǵٽ� ���´ٴ� ��
			else if (ch == ' ')
			{
				resultString += GetStringFromStack(myStack);
				resultString += ' ';
			}

			// �ܾ��� ��� ������ ���ڱ��� �����ߴµ�, ' '�� ������ ���ϱ� ������ ���� �����Ų��.
			if (i == length - 1)
			{
				resultString += GetStringFromStack(myStack);
				break;
			}
		}
		// �±��� ���
		else
		{
			// ������ ���ÿ� �ִ´�.
			myStack.push(ch);

			// �±��� ���� �˸��� '>'�� ������
			if (ch == '>')
			{
				// �±׸� ���� �ӽ� ���ڿ��� �ְ� �ٽ� ��������
				const std::string temp = GetStringFromStack(myStack);
				resultString += ReverseString(temp);

				isTag = false;
			}
		}
	}

	return resultString;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : �ܾ� ������ 2 - �������� �ذ�

	std::string str;
	std::getline(cin, str);

	cout << Solution(str) << '\n';

	return 0;
}
