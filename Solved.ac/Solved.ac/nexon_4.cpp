#include <bits/stdc++.h>
using namespace std;

class Star
{
public:
	int ID;
	unordered_set<Star*> Links;

public:
	Star(int _id) {
		this->ID = _id;
	}
};

int M, N;
int a, b;
int result = 0;

unordered_map<int, Star*> registered;
unordered_map<int, bool> globalVisited;

int DFS(int  id, int cnt) {
	Star* star = registered[id];
	for (const auto& linkedStar : star->Links) {
		if (globalVisited[linkedStar->ID]) continue;
		globalVisited[linkedStar->ID] = true;
		cnt += DFS(linkedStar->ID, 1);
	}
	return cnt;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ���ֿ���! �����ۿ�Ȧ!

	/// [Ǯ�� ���]
	/// 
	/// ID�� �ּҰ��� 0, �ִ밪�� 2147483647�̱� ������ �迭�� �ε����δ� ID�� ������ �� ����.
	/// ���� �ؽ� ���̺��� �̿��� ID�� �����Ѵ�
	/// 
	/// �ش� ���������� ���� ���� �̾����ִ°�?�� ���ؼ� �����ϹǷ�, ������ ������� �ʾƵ� �ȴ�
	/// ���� �޸𸮸� �� ����ϴ��� unordered_map, unordered_set �� �ؽ� ���̺��� ����� �ð� ���⵵ O(1)�� ����, �˻��� �����Ѵ�
	/// 
	/// global visited�� �����, �� �� �湮�� ���� ��湮���� �ʴ´�.
	/// �ֳ��ϸ� a <----> b �� ���� ����� �׷����ӿ��� '����Ǿ� �ִ�����' �˸� �Ǳ� �����̴�.

	cin >> M;       // �����ۿ�Ȧ ����
	cin >> N;       // �̵� ������ ���� �ּ� ����

	registered.reserve(2 * M);

	for (int i = 0; i < M; ++i) {
		cin >> a >> b;		// ���� ID ��

		// ��ϵ��� ���� ���� ID�� ���
		if (registered.count(a) == 0) {
			registered[a] = new Star(a);
			globalVisited[a] = false;
		}
		if (registered.count(b) == 0) {
			registered[b] = new Star(b);
			globalVisited[b] = false;
		}
		// a�� b������ ��Ȧ�� ����
		registered[a]->Links.insert(registered[b]);
		registered[b]->Links.insert(registered[a]);
	}

	// �� ���� ���� ����� ������ Ÿ�� ���鼭 ����� ���� ������ ����Ѵ�
	for (const auto& r : registered) {
		if (globalVisited[r.first]) continue;
		globalVisited[r.first] = true;
		int linkCount = DFS(r.first, 1);
		if (linkCount <= N) {
			result += linkCount;
		}
	}

	cout << result;

	return 0;
}

// ����� �����ۿ�Ȧ�� ������ Ȯ���ϰ�
// a, b �� ����� �� �ִ� ���� �ִٸ�
// �ش� ������ '����'�Ѵ�

// ��� 1. n��° �Է¿��� 1 ~ n��° ��Ȧ�� ���� �� a�� ���ԵǾ� �ִٸ�
// b�� �ش� ��Ȧ ������ �̾� ������ (�׷����Ѵ�) => Ȥ�� ������ ���� ���� �ְڴ�

// ��� 2. n��° �Է¿��� 1 ~ n��° ��Ȧ�� ���� �� b�� ���ԵǾ� �ִٸ�
// a�� �ش� ��Ȧ ������ �̾� ������ (�׷����Ѵ�) => Ȥ�� ������ ���� ���� �ְڴ�

// ��� 3. n��° �Է¿��� 1 ~ n��° ��Ȧ�� ���� �� a�� b�� ���ÿ� ���ԵǾ� �ִٸ�
// (�ϳ��� ��Ȧ ������) �Էµ� ���� ó������ �ʰ� ��ŵ�Ѵ�

// ��� 4. n��° �Է¿��� 1 ~ n��° ��Ȧ�� ���� �� a�� b�� ���� �ٸ� (a�� k��° b�� l��°)
// ��Ȧ ������ ���ԵǾ� �ִٸ� k��°�� l��° ��Ȧ�� �����Ѵ�.

// ���: �̷ν� ��� ��Ȧ�� ������ ��
// (�Է¹��� �����ۿ�Ȧ�� ������ M�� ������, �����δ� ������ ���� �̷���� �׺��� ���ų� ���� ���̴�)
// ���� ��ġ�� ���� ID�� ������ ���̴�. (�ֳ��ϸ� ��ġ�� ID�� ���� ������ ������ �ؿԱ� �����̴�)
// ���� ��� ��Ȧ�� �������� ��ġ�� �ʴ� ���� ID���� �����ϰ� ���� ���̰�, �̴� �׷����� �Ϸ�Ǿ����� �ǹ��Ѵ�.


	/*
	for (const auto& r : registered) {
		cout << '[' << r.first << "] ===== > ";
		for (const auto& s : r.second->Links) {
			cout << s->ID << ' ';
		}
		cout << '\n';
	}
	*/