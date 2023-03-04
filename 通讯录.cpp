//通讯录管理系统
//目前有一个bug，添加联系人时如果在年龄项输入非数字会导致程序结束(；′⌒`)

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
//显示菜单
void menu() {
	cout << "1.添加联系人" << endl;
	cout << "2.显示联系人" << endl;
	cout << "3.删除联系人" << endl;
	cout << "4.查找联系人" << endl;
	cout << "5.修改联系人" << endl;
	cout << "6.清空通讯录" << endl;
	cout << "0.退出通讯录" << endl;
}
//联系人
struct contacts {
	string name;
	string phonenumber;
	int gender;//性别1男2女
	int age;
	string address;
};
//通讯录
struct addressbook {
	contacts contactsarr[MAX];
	int size;
};
//添加联系人
void addcontacts(addressbook* txl) {
	if (txl->size == MAX)
	{
		cout << "通讯录已满，请删除联系人" << endl;
		return;
	}
	else
	{
		string name;//姓名
		cout << "请输入联系人姓名：" <<endl ;
		cin >> name;
		txl->contactsarr[txl->size].name = name;

		cout << "请输入联系人电话：" << endl;
		string num;
		cin >> num;
		txl->contactsarr[txl->size].phonenumber = num;
		cout << "请输入联系人性别：" << endl;
		cout << "输入1---男      2------女"<<endl;
		int gender = 0;
		while (1) {
			cin >> gender;
			if (gender == 1 || gender == 2) {
				txl->contactsarr[txl->size].gender = gender;
				break;
			}
			else
			{
				cout << "请输入1或2" << endl;
				cout << "输入1---男      2------女" << endl;
			}
		}
		cout << "请输入联系人年龄：" << endl;
		int age=0;
		cin >> age;
		txl->contactsarr[txl->size].age = age	;
		cout << "请输入联系人地址：" << endl;
		string address;
		cin >> address;
		txl->contactsarr[txl->size].address = address;
		txl->size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
void display(addressbook* txl) {
	if (txl->size == 0) {
		cout << "当前通讯录没有联系人" << endl;
	}
	else {
		for (int i = 0; i < txl->size; i++) {
			cout << "联系人姓名：" << txl->contactsarr[i].name << endl;
			cout << "联系人电话号码：" << txl->contactsarr[i].phonenumber << endl;
			if (txl->contactsarr[i].gender == 1) {
				cout << "联系人性别：男" << endl;
			}
			else
				cout << "联系人性别：女" << endl;
			cout << "联系人年龄：" << txl->contactsarr[i].age << endl;
			cout << "联系人地址：" << txl->contactsarr[i].address << endl;
		}
	}
	system("pause");//按任意键继续
	system("cls");//清屏
}
//检测联系人是否存在
int check(addressbook* txl,string name) {
	for (int i = 0; i < txl->size; i++) {
		if (txl->contactsarr[i].name == name)
			return i;//遍历
	}
	return -1;//没找到
}
void deletecontacts(addressbook* txl) {
	
		cout << "请输入要删除联系人：" << endl;
		string name;
		cin >> name;
		int ret = check(txl, name);
		if (ret == -1)
			cout << "未查找到该联系人" << endl;
		else
		{
			for (int i = ret; i < txl->size; i++)
				txl->contactsarr[i] = txl->contactsarr[i + 1];
			txl->size--;
			cout << "已删除成功" << endl;
		}

		system("pause");
		system("cls");
}
void seek(addressbook* txl)
{
	cout << "请输入要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = check(txl, name);
	if (ret == -1)
		cout << "未查找到该联系人" << endl;
	else {
		cout << "联系人姓名：" << txl->contactsarr[ret].name << endl;
		cout << "联系人电话：" << txl->contactsarr[ret].phonenumber << endl;
		cout << "联系人性别：" << txl->contactsarr[ret].gender << endl;
			cout << "联系人年龄：" << txl->contactsarr[ret].age << endl;
		cout << "联系人地址：" << txl->contactsarr[ret].address << endl;
	}
	system("pause");
	system("cls");
}
void revise(addressbook* txl)
{
	cout << "请输入要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = check(txl, name);
	if (ret == -1)
	{
		cout << "未查找到该联系人" << endl;
		system("pause");
		system("cls");
	}
	else {
		string name;//姓名
		cout << "请输入联系人姓名：" << endl;
		cin >> name;
		txl->contactsarr[ret].name = name;

		cout << "请输入联系人电话：" << endl;
		string num;
		cin >> num;
		txl->contactsarr[ret].phonenumber = num;
		cout << "请输入联系人性别：" << endl;
		cout << "输入1----男      2------女" << endl;
		int gender = 0;
		while (1) {
			cin >> gender;
			if (gender == 1 || gender == 2) {
				txl->contactsarr[ret].gender = gender;
				break;
			}
			else
			{
				cout << "请输入1或2" << endl;
				cout << "输入1---男      2------女" << endl;
			}
		}
		cout << "请输入联系人年龄：" << endl;
		int age = 0;
		cin >> age;
		txl->contactsarr[ret].age = age;
		cout << "请输入联系人地址：" << endl;
		string address;
		cin >> address;
		txl->contactsarr[ret].address = address;
		cout << "修改成功" << endl;
		system("pause");
		system("cls");
	}
}
void clean(addressbook *txl) {
	txl->size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

int main(){
	addressbook txl;
	txl.size = 0;
	while (1) {
		menu();
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1://1.添加联系人
			addcontacts(&txl);
			break;
		case 2://2.显示联系人
			display(&txl);
			break;
		case 3://3.删除联系人
			deletecontacts(&txl);
			break;
		case 4://4.查找联系人
			seek(&txl);
			break;
		case 5://5.修改联系人
			revise(&txl);
			break;
		case 6://6.清空通讯录
			clean(&txl);
			break;
		case 0://0.退出通讯录
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}