#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : Strfry

    int N; cin >> N;
    while (N--) {
        string a, b;
        cin >> a >> b;

        /// ��� 1 : ���鼭 üũ�ϱ�
        /*
        // char : 1byte(8bit) = 0 <= x <= 127
        int arr[128] = {};

        if (a.length() != b.length()) {
            cout << "Impossible" << '\n';
            continue;
        }

        int length = a.length();
        for (int i = 0; i < length; i++) {
            arr[a[i]]++;
        }
        bool isPossible = true;
        for (int i = 0; i < length; i++) {
            if (arr[b[i]] > 0)
                arr[b[i]]--;
            else {
                isPossible = false;
                break;
            }
        }
        */

        /// ��� 2 : ������ üũ�ϱ� (���������� �̰� ���)
        // char : 1byte(8bit) = 0 <= x <= 127
        int arr1[128] = {};
        int arr2[128] = {};

        for (const auto c : a) {
            arr1[c]++;
        }
        for (const auto c : b) {
            arr2[c]++;
        }
        bool isPossible = true;
        for (const auto c : b) {
            if (arr1[c] != arr2[c]) {
                isPossible = false;
                break;
            }
        }

        if (isPossible)
            cout << "Possible" << '\n';
        else
            cout << "Impossible" << '\n';
    }

    return 0;
}
