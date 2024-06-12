#include <bits/stdc++.h>
using namespace std;

int N;  // ����� ���ϴ� ��� Ƚ��

string prefix = "____";

string str1 = "\"����Լ��� ������?\"";
string str2 = "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.";
string str3 = "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.";
string str4 = "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"";
string str5 = "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"";
string str6 = "��� �亯�Ͽ���.";

void _Bar(int n, string str) {
    for (int i = 0; i < n; i++) {
        cout << prefix;
    }
    cout << str << '\n';
}

void ChatBot(int n)
{
    // start
    _Bar(N - n, str1);

    if (n == 0) {
        _Bar(N - n, str5);
        _Bar(N - n, str6);
        return;
    }

    _Bar(N - n, str2);
    _Bar(N - n, str3);
    _Bar(N - n, str4);

    ChatBot(n - 1);

    // end
    _Bar(N - n, str6);

    return;
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : ����Լ��� ������?

    cin >> N;

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';

    ChatBot(N);

    return 0;
}
