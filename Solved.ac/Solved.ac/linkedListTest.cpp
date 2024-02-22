#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
int datas[MAX], prePointer[MAX], nextPointer[MAX];
int newIndex = 1;

void insert(int frontAddress, int number) {
    datas[newIndex] = number;

    prePointer[newIndex] = frontAddress;
    nextPointer[newIndex] = nextPointer[frontAddress];

    if (nextPointer[frontAddress] != -1) {  // ���� ��Ұ� ����Ű���� �ִٸ�
        prePointer[nextPointer[frontAddress]] = newIndex;
    }
    nextPointer[frontAddress] = newIndex;

    newIndex++;
}

void erase(int address) {
    //datas[address] = -1;
    
    nextPointer[prePointer[address]] = nextPointer[address];    // ���� ��Ұ� ���� ���� ���� (����ȴ�. Dummy Node ������)
    if (nextPointer[address] != -1) {
        prePointer[nextPointer[address]] = prePointer[address]; // ������ ��Ұ� ���� ��츦 ���
    }

    //prePointer[address] = -1;
    //nextPointer[address] = -1;
}

void traverse() {
    int current = nextPointer[0];
    while (current != -1) {
        cout << datas[current] << ' ';
        current = nextPointer[current];
    }
    cout << "\n\n";
}

void insert_test() {
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)                 // '0����' �ڿ� 10�� �߰��Ѵ�
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test() {
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(void) {
    fill(prePointer, prePointer + MAX, -1); 
    fill(nextPointer, nextPointer + MAX, -1);
    insert_test();
    erase_test();
}