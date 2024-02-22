#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : �似Ǫ�� ����

    // 1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�
    // ���� ���� K(�� N)�� �־�����. ���� ������� K��° ����� �����Ѵ�
    //
    // �� ����� ���ŵǸ� ���� ������ �̷���� ���� ���� �� ������ ����� ������.
    // �� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�
    // 
    // ������ ������� ���ŵǴ� ������ (N, K)-�似Ǫ�� ����
    // ���� ��� (7, 3)-�似Ǫ�� ������ <3, 6, 2, 7, 5, 1, 4>�̴�.
    //
    // N�� K�� �־����� (N, K)-�似Ǫ�� ������ ���ϴ� ���α׷��� �ۼ�

    int N, K;
    cin >> N >> K;

    list<int> myList;
    for (int i = 1; i <= N; i++) {
        myList.push_back(i);
    }

    cout << '<';

    auto iter = myList.begin();
    while (!myList.empty()) {

        // 2ĭ �����ϱ�
        for (int i = 0; i < K - 1; i++) {
            iter++;
            if (iter == myList.end()) iter = myList.begin();
        }

        // K��° ��ȣ ���
        if (myList.size() == 1) cout << *iter;
        else cout << *iter << ", ";

        // K��° ��ȣ ����
        iter = myList.erase(iter);
        if (iter == myList.end()) iter = myList.begin();
    }

    cout << '>';

    return 0;
}
