//ͨѶ¼����ϵͳ
//Ŀǰ��һ��bug�������ϵ��ʱ�������������������ֻᵼ�³������(�����`)

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
//��ʾ�˵�
void menu() {
	cout << "1.�����ϵ��" << endl;
	cout << "2.��ʾ��ϵ��" << endl;
	cout << "3.ɾ����ϵ��" << endl;
	cout << "4.������ϵ��" << endl;
	cout << "5.�޸���ϵ��" << endl;
	cout << "6.���ͨѶ¼" << endl;
	cout << "0.�˳�ͨѶ¼" << endl;
}
//��ϵ��
struct contacts {
	string name;
	string phonenumber;
	int gender;//�Ա�1��2Ů
	int age;
	string address;
};
//ͨѶ¼
struct addressbook {
	contacts contactsarr[MAX];
	int size;
};
//�����ϵ��
void addcontacts(addressbook* txl) {
	if (txl->size == MAX)
	{
		cout << "ͨѶ¼��������ɾ����ϵ��" << endl;
		return;
	}
	else
	{
		string name;//����
		cout << "��������ϵ��������" <<endl ;
		cin >> name;
		txl->contactsarr[txl->size].name = name;

		cout << "��������ϵ�˵绰��" << endl;
		string num;
		cin >> num;
		txl->contactsarr[txl->size].phonenumber = num;
		cout << "��������ϵ���Ա�" << endl;
		cout << "����1---��      2------Ů"<<endl;
		int gender = 0;
		while (1) {
			cin >> gender;
			if (gender == 1 || gender == 2) {
				txl->contactsarr[txl->size].gender = gender;
				break;
			}
			else
			{
				cout << "������1��2" << endl;
				cout << "����1---��      2------Ů" << endl;
			}
		}
		cout << "��������ϵ�����䣺" << endl;
		int age=0;
		cin >> age;
		txl->contactsarr[txl->size].age = age	;
		cout << "��������ϵ�˵�ַ��" << endl;
		string address;
		cin >> address;
		txl->contactsarr[txl->size].address = address;
		txl->size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
void display(addressbook* txl) {
	if (txl->size == 0) {
		cout << "��ǰͨѶ¼û����ϵ��" << endl;
	}
	else {
		for (int i = 0; i < txl->size; i++) {
			cout << "��ϵ��������" << txl->contactsarr[i].name << endl;
			cout << "��ϵ�˵绰���룺" << txl->contactsarr[i].phonenumber << endl;
			if (txl->contactsarr[i].gender == 1) {
				cout << "��ϵ���Ա���" << endl;
			}
			else
				cout << "��ϵ���Ա�Ů" << endl;
			cout << "��ϵ�����䣺" << txl->contactsarr[i].age << endl;
			cout << "��ϵ�˵�ַ��" << txl->contactsarr[i].address << endl;
		}
	}
	system("pause");//�����������
	system("cls");//����
}
//�����ϵ���Ƿ����
int check(addressbook* txl,string name) {
	for (int i = 0; i < txl->size; i++) {
		if (txl->contactsarr[i].name == name)
			return i;//����
	}
	return -1;//û�ҵ�
}
void deletecontacts(addressbook* txl) {
	
		cout << "������Ҫɾ����ϵ�ˣ�" << endl;
		string name;
		cin >> name;
		int ret = check(txl, name);
		if (ret == -1)
			cout << "δ���ҵ�����ϵ��" << endl;
		else
		{
			for (int i = ret; i < txl->size; i++)
				txl->contactsarr[i] = txl->contactsarr[i + 1];
			txl->size--;
			cout << "��ɾ���ɹ�" << endl;
		}

		system("pause");
		system("cls");
}
void seek(addressbook* txl)
{
	cout << "������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = check(txl, name);
	if (ret == -1)
		cout << "δ���ҵ�����ϵ��" << endl;
	else {
		cout << "��ϵ��������" << txl->contactsarr[ret].name << endl;
		cout << "��ϵ�˵绰��" << txl->contactsarr[ret].phonenumber << endl;
		cout << "��ϵ���Ա�" << txl->contactsarr[ret].gender << endl;
			cout << "��ϵ�����䣺" << txl->contactsarr[ret].age << endl;
		cout << "��ϵ�˵�ַ��" << txl->contactsarr[ret].address << endl;
	}
	system("pause");
	system("cls");
}
void revise(addressbook* txl)
{
	cout << "������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = check(txl, name);
	if (ret == -1)
	{
		cout << "δ���ҵ�����ϵ��" << endl;
		system("pause");
		system("cls");
	}
	else {
		string name;//����
		cout << "��������ϵ��������" << endl;
		cin >> name;
		txl->contactsarr[ret].name = name;

		cout << "��������ϵ�˵绰��" << endl;
		string num;
		cin >> num;
		txl->contactsarr[ret].phonenumber = num;
		cout << "��������ϵ���Ա�" << endl;
		cout << "����1----��      2------Ů" << endl;
		int gender = 0;
		while (1) {
			cin >> gender;
			if (gender == 1 || gender == 2) {
				txl->contactsarr[ret].gender = gender;
				break;
			}
			else
			{
				cout << "������1��2" << endl;
				cout << "����1---��      2------Ů" << endl;
			}
		}
		cout << "��������ϵ�����䣺" << endl;
		int age = 0;
		cin >> age;
		txl->contactsarr[ret].age = age;
		cout << "��������ϵ�˵�ַ��" << endl;
		string address;
		cin >> address;
		txl->contactsarr[ret].address = address;
		cout << "�޸ĳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
void clean(addressbook *txl) {
	txl->size = 0;
	cout << "ͨѶ¼�����" << endl;
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
		case 1://1.�����ϵ��
			addcontacts(&txl);
			break;
		case 2://2.��ʾ��ϵ��
			display(&txl);
			break;
		case 3://3.ɾ����ϵ��
			deletecontacts(&txl);
			break;
		case 4://4.������ϵ��
			seek(&txl);
			break;
		case 5://5.�޸���ϵ��
			revise(&txl);
			break;
		case 6://6.���ͨѶ¼
			clean(&txl);
			break;
		case 0://0.�˳�ͨѶ¼
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}