#pragma once

#include<string>

#define MAX 1000

class ͨѶ¼
{
public:
	void showMenu();
	void addPerson();
	void showContacts();
	void deleteContact();
	void resetContact();
	void removeAllContacts();
	void exitMenu();
	typedef struct _contactBook{
		int count;		//�ۼ���������ţ�
		string name;	
		bool sex;		//1-�� 0-Ů
		int age;
		string phoneNumber;		//�绰����
		string address;
	};
	_contactBook Person[MAX];
};

