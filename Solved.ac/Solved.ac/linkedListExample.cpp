#include <bits/stdc++.h>
using namespace std;

int main(void) {
    list<int> myList = { 1,2 }; // �ʱ�ȭ ����Ʈ (lnitial list) -> 1 2

    list<int>::iterator iter = myList.begin(); // iter�� 1�� ����Ų��

    // ���� ������ ��� or ���� ó�� ��ҿ� �����͸� �����ϴ� ���� �ش� ���Ҹ� ã���� ���� ��������
    // �ٸ� ���Ҹ� Ÿ�� �ʿ䰡 �����Ƿ� O(1)�� �ð����⵵�� ������ ������ �����ϴ�
    myList.push_front(10); // 10 1 2
    cout << *iter << '\n'; // iter�� ����Ű�� �� = 1�� ��� (�̹� ����Ű�� �־���)
    myList.push_back(5); // 10 1 2 5
    myList.insert(iter, 6); // iter�� ����Ű�� �� '�տ�' 6�� ����, 10 6 1 2 5

    // operator ++�� ������ ������ ���� ����Ʈ�� ���� �ڷᱸ���̱� �����̴�
    iter++; // iter�� 1ĭ ������ ����, ���� iter�� ����Ű�� ���� 2

    // iter�� ����Ű�� ���� ����, �� ���� ������ 5�� ��ġ�� ��ȯ
    iter = myList.erase(iter); // 10 6 1 5, iter�� ����Ű�� ���� 5
    cout << *iter << '\n'; // 5

    // c++ 11 later : range based loop
    for (auto i : myList) cout << i << ' ';

    cout << '\n';

    // c++ 11 earlier : primitive loop
    for (list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        cout << *it << ' ';
}