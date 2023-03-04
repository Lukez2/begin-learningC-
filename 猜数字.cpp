#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main() {
	//生成随机数
	int num = rand() % 100 + 1;
	//猜数字
	int guess = 0;
	//判断
	while (1) {
		cout << "请输入一个1~100的数字" << endl;
		cin >> guess;

		if (guess > num)
		{

			cout << "猜大了！" << endl;
			continue;
		}
		else if (guess < num)
		{
			cout << "猜小了！" << endl;
			continue;
		}
		else if (guess == num)
		{
			cout << "猜对了！" << endl;
			break;
		}
		else
		{
			cout << "请输入一个1~100的数字！" << endl;
			continue;
		}
	}
	return 0;
}