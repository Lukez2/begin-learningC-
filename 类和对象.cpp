#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class student {
public:
	string name;
	string num;
	void print() {
		cout << "ÐÕÃû£º" << name <<"  ";
		cout << "Ñ§ºÅ£º" << num << endl;
	}
};


int main() {
	student a1;
	a1.name = "levi";
	a1.num = "123456";
	a1.print();
		return 0;
}