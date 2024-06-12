#include <bits/stdc++.h>
using namespace std;

int N; // �� ���� ����
bool paper[130][130];
int paperCount[2];

bool CheckAllSame(int ltr, int ltc, int length)
{
    int firstNumber = paper[ltr][ltc];
    for (int row = ltr; row < ltr + length; row++) {
        for (int col = ltc; col < ltc + length; col++) {
            if (firstNumber != paper[row][col]) return false;
        }
    }

    return true;
}

void Func(int ltr, int ltc, int length) {

    // ��� ���� ������ ĥ���� �ִ��� Ȯ���Ѵ�.
    if (CheckAllSame(ltr, ltc, length))
    {
        int paperNumber = paper[ltr][ltc];
        paperCount[paperNumber]++;
        return;
    }

    // ����� �� �ִ��� üũ�Ѵ� (base condition)
    if (length < 2) return;

    // 4��� �Ѵ�
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            Func(ltr + length / 2 * row, ltc + length / 2 * col, length / 2);
        }
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : ������ �����

    // ��ü ���̰� ��� ���� ������ ĥ���� ���� ������
    // ���ο� ���η� �߰� �κ��� �߶�

    // ��� �Ͼ�� �Ǵ� ��� �Ķ������� ĥ���� �ְų�,
    // �ϳ��� ���簢�� ĭ�� �Ǿ� �� �̻� �ڸ� �� ���� ������ �ݺ�

    // �Ͼ������ ĥ���� ĭ�� 0
    // �Ķ������� ĥ���� ĭ�� 1

    cin >> N;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> paper[row][col];
        }
    }

    Func(0, 0, N);

    std::cout << paperCount[0] << '\n';
    std::cout << paperCount[1] << '\n';

    return 0;
}
