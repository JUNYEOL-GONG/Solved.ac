#include <iostream>
#include <vector>

using namespace std;

class Student
{
public:
	string name;
	int age;

public:
	Student()
	{
		std::cout << "���� ���� �⺻ ������" << std::endl;
	}
	Student(string n, int a)
	{
		std::cout << "���� �ִ� �⺻ ������" << std::endl;
	}
	Student(const Student& s)
	{
		std::cout << "���� ������" << std::endl;
	}
	Student(const Student&& s)
	{
		std::cout << "�̵� ������" << std::endl;
	}
	~Student()
	{
		std::cout << "�Ҹ���" << std::endl;
	}
};

void MyFunc()
{
	std::vector<Student> myVector;
	myVector.reserve(2);

	myVector.push_back(Student("����Ŀ", 27));

	cout << "======================================================" << endl;

	myVector.emplace_back("����Ʈ", 27);

	cout << "======================================================" << endl;
}

int main()
{
	MyFunc();

	cout << "==================== End MyFunc() ====================" << endl;

	return 0;
}
