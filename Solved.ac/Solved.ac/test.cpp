#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

#ifdef _DEBUG
	cout << "<����� ���>" << "\n\n";
#else
	cout << "<������ ���>" << "\n\n";
#endif

	int a = 10;
	int b = 20;

	std::cout << "���� a�� �ּ�: " << &a << '\n';
	std::cout << "���� b�� �ּ�: " << &b << "\n\n";

	// �ּ� ���� ���
	ptrdiff_t diff = reinterpret_cast<char*>(&b) - reinterpret_cast<char*>(&a);

	std::cout << "�� ���� ������ �޸� �ּ� ����: " << diff << " ����Ʈ" << '\n';

	return 0;
}
