// �ڵ� �׽�Ʈ������ �������� �ð��� �߿��ϴ�
// ���� �˰����� ������ ȿ���� �Ű澲�� �ʴ´�
// ����, �ٹٲ�, ��� ���� �׸��� �Ű���

#include <bits/stdc++.h>						// 1. ������� ���̺귯��
using namespace std;							// 2. ���ӽ����̽� std ���
int length, target, answer[10005], duration;				// 3. ���������� ���� (+ �迭 ũ�� �˳��ϰ� ���)
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> length >> target;

	// �迭 ����ϴ� ���
	for (int i = 0; i < length; ++i) cin >> answer[i];
	for (int i = 0; i < length; ++i)
		if (answer[i] < target) cout << answer[i] << ' ';

	// �迭 ������� �ʴ� ���
	while (length--) {							// 4. �ܼ��� Ƚ�� �ݺ��̶�� while�� �������
		cin >> duration;
		if (duration < target) cout << duration << ' ';
	}

	return 0;
}