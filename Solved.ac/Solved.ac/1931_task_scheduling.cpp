#include <bits/stdc++.h>
using namespace std;

int N;

//int s[100005];  // 100000 * 4 byte = 0.4MB (�������� ��������)
//int e[100005];

pair<int, int> task[100005];    // 100000 * 8 = 0.8MB

/// <summary>
/// compare �Լ��� ���ڷ� ���� ���� �� �ִµ�
/// �׷����� task�� first�� end time�� �־��ְ�
/// task�� second�� start time�� �־��ָ�
/// �ڵ����� end time -> start time �켱������ '��������' ������ ������ ���̴�
/// </summary>
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : ȸ�ǽ� ����

    // �׸��� �˰����� ����� ����ٰ� �ϸ�
    // ó���� 'Task Scheduling Problem'�̶�� ���� �������� ���غ��� �����̴�.

    // ���� ���ø� �׸��� �˰����� Ǯ�̰� ������ ���ش� �־
    // ���� ���ϰ� '���߿� ���� �� �̵��� ���'�� ������ ���캻��

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> task[i].first >> task[i].second;
    }

    // ������ �ð��� �������� �������� �����Ѵ�
    // ���ٸ� �����ϴ� �ð��� �������� �������� �����Ѵ�

    // ������ �ð��� ���ٸ� �����ϴ� �ð��� ���� ������� �����ؾ� �ϴ� ������
    // (1, 4) (5, 5) (4, 5)�� ��츦 ������ ���� �� �� �ִ�.
    // �������ڸ��� ������ ��츦 ����Ϸ��� �����ϴ� �ð��� �������ε� �����ؾ� �Ѵ�

    sort(task, task + N, compare);  // �ð� ���⵵: O(NlogN)

    // ���� Task�� �����Ѵ�
    // ���� �ð� ���Ŀ� �����ϴ� ȸ�Ǹ� ã�´�
    // �� ȸ�Ǹ� �ٽ� ���� Task�� �����Ѵ�
    // ȸ�ǰ� ���̻� ���� ������ �Ѵ�

    int res = 1;

    /*
    
    // ��� 1

    // ���� for������ O(N^2)ó�� ��������
    // ���� for������ i�� j�� �ǳʶٵ��� �ϱ� ������
    // �ᱹ ��� ȸ�Ǹ� �ѹ����� �˻��ϰ� �ȴ�.
    // ���� O(N)
    for (int i = 0; i < N; ++i) {   // origin
        for (int j = i + 1; j < N; ++j) {   // target
            if (task[i].second <= task[j].first) {
                res++;
                i = j - 1;
                break;
            }
        }
    }
    */

    // ��� 2

    int temp = task[0].second;

    // �ð� ���⵵: O(N) - ���������� O(N)�̴�
    for (int i = 1; i < N; ++i) {
        if (temp <= task[i].first) {
            temp = task[i].second;
            res++;
        }
    }

    // ��� 1������ ���������� �ð����⵵�� O(N)������ '��� ����'�� �� ũ�� i.e) O(100N)
    // ��� 2������ ������ ȿ�������� �ٿ��� ������ ���� O(N)�� �ð����⵵�� ȿ�����̴� i.e) O(50N)
    // 
    // ���� �˰����� ����Ѵٰ� �ϴ��� �ڵ带 ��� ¥���Ŀ� ����
    /// '������ ��� ����'�� �޶��� ������ �ð� ���⵵ ������ �ʿ��� ���������� ������ ���� �� �ִ�

    cout << res;

    return 0;
}
