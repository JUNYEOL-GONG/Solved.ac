#include <bits/stdc++.h>
using namespace std;

int N;
string input;
vector<string> words;

vector<int> f;      // KMP �˰��� ���� �Լ�

/// <summary>
/// �κ� ���ڿ��� ���� '���� �Լ�'�� ����Ѵ�
/// </summary>
void CalcFailureFunc(string& subStr) {

    // f(k) : S[0:k+1)���� S[0:x]�� S[x:|S|]�� ��ġ�ϴ� �ִ� ����
    // subStr: 0 1 2 ...| ... k-1 |						=> ���̻� �κ�
    // subStr: 			|0 1 2 ...| ... k-1				=> ���λ� �κ�
    //
    // �������� f(k) <= f(k-1) + 1���� �� �� �ִ�
    // ���� f(k)�� �ִ� ���̸� f(k-1) + 1���� �����ϸ� üũ�Ѵ�
    // 
    // ���� ������ �ٰŷ�, ���� S[f(K-1)] == S[K]���
    // f(k) = f(k-1) + 1�̴�
    //
    // �׷��� �ʴٸ� �̹� ���س��� �����Լ��� ���� �̿���
    // ���������� �󸶳� �̵�����(j�� �� �Ҵ�) ���ϴ� �� Ű����Ʈ

    f.clear();
    f.resize(subStr.size());
    f[0] = 0;				    // S[0:1]������ �ڱ� �ڽŸ� ����

    int i, j = 0;
    for (i = 1; i < subStr.size(); ++i) {
        while (j > 0) {
            if (subStr[i] == subStr[j]) break;
            j = f[j - 1];
        }
        if (subStr[i] == subStr[j]) {
            f[i] = ++j;
        }
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : �弳����

    // [KMP �˰���]
    // 
    // �Ϲ����� ���ڿ� �˻�(���� ��Ī)�� O(|S1| x |S2|)�� �̷������
    // ���ڿ��� ���̰� ��ų�, �־��� ��� (���ڿ� S1�� �� ��ġ���� O(|S2|�� �񱳸� �ϴ� ���) �ð��� �ʰ��� �� �ִ�.
    //
    // KMP�� ���� ��Ī�� O(|S1| + |S2|)�� �ذ��� �� �ִ�
    // �κ� ���ڿ����� �ڱ� �ڽ��� �����ϰ� ���λ�� ���̻簡 ��ġ�ϴ� �ִ� ���̸�
    // ����� �����ϴ� '���� �Լ�'�� �ٽ��̴�.

    cin >> N;
    words.reserve(N);

    while (N--) {
        cin >> input;
        for (auto& word : words) {
            CalcFailureFunc(word);
            int i, j = 0;
            for (i = 0; i < input.size(); ++i) {
                while (j > 0) {
                    if (input[i] == word[j]) break;
                    j = f[j - 1];
                }
                if (input[i] == word[j]) {
                    ++j;
                }
                if (j == word.size()) {
                    cout << input << '\n';
                    goto next_input;
                }
            }
        }

        next_input:;

        words.push_back(input);
    }

    return 0;
}
