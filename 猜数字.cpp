#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main() {
	//���������
	int num = rand() % 100 + 1;
	//������
	int guess = 0;
	//�ж�
	while (1) {
		cout << "������һ��1~100������" << endl;
		cin >> guess;

		if (guess > num)
		{

			cout << "�´��ˣ�" << endl;
			continue;
		}
		else if (guess < num)
		{
			cout << "��С�ˣ�" << endl;
			continue;
		}
		else if (guess == num)
		{
			cout << "�¶��ˣ�" << endl;
			break;
		}
		else
		{
			cout << "������һ��1~100�����֣�" << endl;
			continue;
		}
	}
	return 0;
}