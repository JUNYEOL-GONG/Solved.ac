#include <bits/stdc++.h>
using namespace std;

int N;

const int MAX_SIZE = 130;

int cave[MAX_SIZE][MAX_SIZE];
bool visited_J[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];

void Dijkstra_Function()
{

}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : ��� �� ���� �ְ� ������?

    while (true)
    {
        cin >> N;

        if (N == 0)
            break;

        // i = N (����), j = N (����)
        // �̷��� �ϹǷν�, ��ġ���ȭ �Ѵ�
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int k; cin >> k;
                cave[j][i] = k;
            }
        }

        // �ִ� �Ÿ� �ʱ�ȭ
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[j][i] = cave[j][i];
            }
        }

        // dijksta�� start ��带 �������� ��� �������� �ִ� �Ÿ��� ���ϴ� �˰����̴�.
        // Dijkstra_Function(start);

        // [0, 0] -> [N-1, N-1]
        cout << "Problem " << N + 1 << ": " << dist[N - 1][N - 1] << '\n';
    }

    return 0;
}
