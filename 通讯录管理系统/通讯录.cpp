#include "通讯录.h"

#include<iostream>

using namespace std;


void 通讯录::showMenu() {
	cout << "******************************" << endl;
	cout << "*****	1、添加联系人	*****" << endl;
	cout << "*****	2、显示联系人	*****" << endl;
	cout << "*****	3、删除联系人	*****" << endl;
	cout << "*****	4、查找联系人	*****" << endl;
	cout << "*****	5、修改联系人	*****" << endl;
	cout << "***	6、清空联联系人" << "	  ***" << endl;
	cout << "*****	0、退出通讯录	*****" << endl;
	cout << "******************************" << endl;
}

void 通讯录::addPerson()
{
	cout << "通讯录已满" << endl;
	/*static int i = 0;
	if(Person[i].count>MAX) {
		cout << "通讯录已满" << endl;
	}
	cout << "请输入姓名:" << endl;
	cin >> Person[i].name;
	cout << Person[i].name;
	i++;*/
	return;
}



void 通讯录::exitMenu() {
	cout << "欢迎下次使用" << endl;
	system("pause");
}




