#pragma once

#include<string>

#define MAX 1000

class 通讯录
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
		int count;		//累计人数（编号）
		string name;	
		bool sex;		//1-男 0-女
		int age;
		string phoneNumber;		//电话号码
		string address;
	};
	_contactBook Person[MAX];
};

