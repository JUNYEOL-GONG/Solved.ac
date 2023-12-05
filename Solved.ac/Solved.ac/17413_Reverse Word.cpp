#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;

std::string ReverseString(std::string inputString)
{
	const size_t length = inputString.length();

	for (size_t i = 0; i < length / 2; ++i)
		std::swap(inputString[i], inputString[length - 1 - i]);

	return inputString;
}

std::string Solution(const std::string& inputString)
{
	std::vector<std::string> words;
	std::vector<std::string> tags;

	std::vector<std::pair<std::string, bool>> stringVector;

	std::string resultString;

	const size_t length = inputString.length();

	// �������� �ܾ�� �̷���� �ϳ��� "����"

	// ������ "�ܾ�"�� "�±�"�� �̷����

	// �켱 �±״� �����ϰ� �ܾ �����ϴ� ���
	// �ܾ�� �������� �̷����

	bool isTag = false;

	size_t startIndex = 0;
	for (size_t i = 0; i < length; ++i)
	{
		// b a e k j o o n
		const char ch = inputString[i];

		if (i == length - 1)
		{
			const size_t count = i - startIndex + 1;
			if(isTag)
				stringVector.emplace_back(inputString.substr(startIndex, count), false);
			else
				stringVector.emplace_back(inputString.substr(startIndex, count), true);
			break;
		}

		if (isTag)
		{
			if (ch == '>')
			{
				const size_t count = i - startIndex + 1;
				stringVector.emplace_back(inputString.substr(startIndex, count), false);
				startIndex += count;
				isTag = false;
			}
		}
		else
		{
			if (ch == ' ')
			{
				const size_t count = i - startIndex;
				stringVector.emplace_back(inputString.substr(startIndex, count), true);
				startIndex += count + 1;
			}
			else if (ch == '<')
			{
				isTag = true;

				if (i != 0)
				{
					const size_t count = i - startIndex;
					stringVector.emplace_back(inputString.substr(startIndex, count), true);
					startIndex += count;
				}
			}
		}
	}

	for (size_t i = 0; i < stringVector.size(); ++i)
	{
		// Word
		if (stringVector[i].second == true)
		{
			// Word�� ��� Reverse
			resultString += ReverseString(stringVector[i].first);

			// ������ �ܾ �ƴ϶��
			if (i != stringVector.size() - 1)
			{
				// ������ Word�� ��� ���� �߰�
				if (stringVector[i + 1].second == true)
					resultString += ' ';
			}
		}
		// Tag
		else
			resultString += stringVector[i].first;
	}


	return resultString;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : �ܾ� ������ 2

	std::string str;
	std::getline(cin, str);

	cout << Solution(str) << '\n';

	return 0;
}
