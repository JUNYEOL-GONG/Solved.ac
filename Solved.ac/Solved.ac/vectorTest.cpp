#include <bits/stdc++.h>
using namespace std;

int main(void) {
	vector<int> v1(3, 5); // {5,5,5};
	cout << v1.size() << '\n'; // 3
	/// push_back()�� �� ������ �ε����� ���� �����Ƿ� O(1)
	/// �߰��� push_front()�� O(N)�̴�
	v1.push_back(7); // {5,5,5,7};

	vector<int> v2(2); // {0,0};
	/// insert()�� �翬�ϰԵ� O(N) (�⺻������ �迭������ ����)
	v2.insert(v2.begin() + 1, 3); // {0,3,0};

	vector<int> v3 = { 1,2,3,4 }; // {1,2,3,4}
	/// erase()�� �翬�ϰ� O(N) (�⺻������ �迭������ ����)
	v3.erase(v3.begin() + 2); // {1,2,4};

	vector<int> v4; // {}
	/// vector STL�� ����
	/// DeepCopy�� �߻��Ѵ�. O(N)
	v4 = v3; // {1,2,4}
	cout << v4[0] << v4[1] << v4[2] << '\n';
	/// pop_back()�� �� ������ �ε����� ���� �����ϴ� ���̹Ƿ� O(1)
	/// �߰��� pop_front()�� O(N)�̴�
	v4.pop_back(); // {1,2}
	/// clear()�� ��� ���(N)���� ���鼭 �����ϱ� ������ O(N)
	v4.clear(); // {}

	/// vector.size()���� �����ϰ� �Ѿ��
	vector<int> test;
	cout << '\n' << test.size() - 1 << '\n';
}