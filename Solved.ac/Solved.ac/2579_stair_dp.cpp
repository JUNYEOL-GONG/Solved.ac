#include <bits/stdc++.h>
using namespace std;

int N;
int stairs[305];

int res = -0x7f7f7f7f;

void DP() {

}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : ��� ������

    // ���ӿ��� ���� �� �ִ� �� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

    // ù ��° ����� ������ ��ƾ� �Ѵ�
    // ���ӵ� �� ����� ���� �� ����
    // �ѹ��� �� ĭ Ȥ�� �� ĭ �ö� �� �ִ�
    // ������ ����� �ݵ�� ��ƾ� �Ѵ�

    cin >> N;
    stairs[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> stairs[i];
    }

    // BFS? �̰� �ִܰŸ� ������ �ƴϱ� ������ �н�

    // ����Լ�? (����)
    // Recursive(0, 0);

    // DP

    // 1. ���̺� �����ϱ�: Dp[i] = i��° ��ܱ��� �ö��� ���� ���� ���� �ִ�
    // 2. ��ȭ�� ã��:
    // Dp[6] .. ����� ����. ���� ���̺��� �ٸ��� �����ؾ� �Ѵ�

    // 1. ���̺� �����ϱ�: Dp[i][j] = ������� j���� ����� �����ؼ� ��� i��° ��ܱ��� �ö��� �� ���� ���� �ִ�

    DP();

    return 0;
}
