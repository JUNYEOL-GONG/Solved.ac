#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // �Ҿ���� ��ȣ
    // + - ()
    // �� ���� ���� '�ּ�'�� ������� �Ѵ�.

    // 55-50+40

    // 5�ڸ����� ���� ���ӵǴ� ���ڴ� ����
    // ���� 0���� ������ �� �ִ�
    // �Է����� �־����� ���� ���̴� 50���� �۰ų� ����

    // * `�ּ�`�� ����� ���ؼ��� -�� Ŀ�����Ѵ�. *
    // -�� ��ȣ�� ������ �ļ� -�� ���� ũ�� �����

    // ** '-' �ڿ� ���� ���� ���� ���� ó���ϸ� ���� ���� �ּҰ� �ȴ�. **

    // ������ 1
    // ���ڿ��� ��� ������ ó���� ���ΰ�?

    // ������ 2
    // ��ȣ�� ��� Ÿ�ֿ̹� ���� ���̰�, ��� �־�� �ϴ°ɱ�?

    string input;
    cin >> input;

    string partialNum;
    const int inputSize = static_cast<int>(input.size());
    int res = 0;
    bool isMinus = false;

    for (int i = 0; i < inputSize; i++)
    {
        // ���� ��ȣ�� ������ ����Ѵ�.
        if (input[i] == '-' || input[i] == '+')
        {
            res += (isMinus ? -1 : 1) * stoi(partialNum);
            partialNum = "";
        }
        // ������ ��쿡�� �κ� ���ڿ��� ���� ����
        else
            partialNum += input[i];

        // '-'�� �� �� ������ �� �ڴ� �� - ��ȣ
        if (input[i] == '-' && !isMinus)
            isMinus = true;
    }

    // Input Data�� ������
    res += (isMinus ? -1 : 1) * stoi(partialNum);
    cout << res;

    return 0;
}