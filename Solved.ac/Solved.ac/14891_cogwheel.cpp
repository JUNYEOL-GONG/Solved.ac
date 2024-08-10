#include <bits/stdc++.h>
using namespace std;

string wheels[10];
bool visited[10];

int K;

void ResetVisited()
{
	for (int i = 1; i <= 4; ++i)
	{
		visited[i] = false;
	}
}

bool CheckLeft(int thisWheelNumber, int leftWheelNumber)
{
	if (leftWheelNumber < 1 || leftWheelNumber > 4)
		return false;

	if (visited[leftWheelNumber] == true)
		return false;

	if (wheels[thisWheelNumber][6] == wheels[leftWheelNumber][2])
		return false;

	return true;
}
bool CheckRight(int thisWheelNumber, int rightWheelNumber)
{
	if (rightWheelNumber < 1 || rightWheelNumber > 4)
		return false;

	if (visited[rightWheelNumber] == true)
		return false;

	if (wheels[thisWheelNumber][2] == wheels[rightWheelNumber][6])
		return false;

	return true;
}

string Shift(string& wheel, int rotateDir)
{
	if (rotateDir == 1)
	{
		char last = wheel[7];
		for (int i = 7; i > 0; --i)
		{
			wheel[i] = wheel[i - 1];
		}
		wheel[0] = last;
	}
	else if (rotateDir == -1)
	{
		char last = wheel[0];
		for (int i = 0; i < 7; ++i)
		{
			wheel[i] = wheel[i + 1];
		}
		wheel[7] = last;
	}

	return wheel;
}

void Rotate(int wheelNumber, int rotateDir)
{
	if (wheelNumber < 1 || wheelNumber > 4)
		return;

	if (visited[wheelNumber] == true)
		return;

	visited[wheelNumber] = true;

	bool isLeft = false;
	bool isRight = false;

	if (CheckLeft(wheelNumber, wheelNumber - 1))
		isLeft = true;
	if (CheckRight(wheelNumber, wheelNumber + 1))
		isRight = true;

	Shift(wheels[wheelNumber], rotateDir);

	if (isLeft)
		Rotate(wheelNumber - 1, (-1) * rotateDir);
	if (isRight)
		Rotate(wheelNumber + 1, (-1) * rotateDir);
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ��Ϲ���

	// 1�� ~ 4������ ���ǵǾ��ִ� ��Ϲ��� Ư���� 1������ �����ϴ� �� ����
	for (int i = 1; i <= 4; ++i)
		cin >> wheels[i];

	cin >> K;

	// �ݸ�, ȸ�� ������ �ε��� ��ȣ�� �߿����� �����Ƿ� �׳� 0���� ����
	for (int i = 0; i < K; ++i)
	{
		int wheelNumber, rotateDir;
		cin >> wheelNumber >> rotateDir;

		Rotate(wheelNumber, rotateDir);

		// ��� �����ۿ��� ���� �� �湮 ���� �ʱ�ȭ
		ResetVisited();
	}

	int result = 0;

	for (int i = 1; i <= 4; ++i)
	{
		// ��.. char�� �ƴ϶� integer�� ���ϰ� ������ �ȵ���..
		if (wheels[i][0] == '1')
		{
			int score = 1 << (i - 1);
			result += score;
		}
	}

	cout << result;

	return 0;
}
