#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : �߰��� ������ �� ���� ����Ʈ�� ���������� �־����� �� ������ ������ ���ϱ�

    list<int> list1 = { 1,2,3,4,5,6,7,8,9,10 };
    for (const auto i : list1) cout << i << ' ';
    cout << '\n';
    cout << '\n';
    list<int> list2 = { 11,12,13,14,15 };
    for (const auto i : list2) cout << i << ' ';
    cout << '\n';
    cout << '\n';
    list<int> list3 = { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 };
    for (const auto i : list3) cout << i << ' ';
    cout << '\n';
    cout << '\n';

    auto iter = list3.begin();

    // ���⿡�� list3�� �������� �Ѵ�
    list1.push_back(*iter);
    list2.push_back(*iter);
    // �̰� �׳� ���� �����ؼ� �ִ� ���̱� ������ ������� �ʴ´�

    for(const auto i : list1) cout << i << ' ';
    cout << '\n';
    cout << '\n';

    for (const auto i : list2) cout << i << ' ';
    cout << '\n';
    cout << '\n';

    for (const auto i : list3) cout << i << ' ';
    cout << '\n';
    cout << '\n';
    return 0;
}
