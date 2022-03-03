
#include<iostream>	
#include<iomanip>
#include"通讯录.h"

using namespace std;


int main() {
	通讯录 client;
	client.showMenu();
	
	int select = 0;

	while (1) {
		cout << "输入指令：" << endl;
		cin >> select;

		if (select < 0 && select>6) {
			cout << "输入指令错误" << endl;
		}
		switch (select)
		{
		case 1:
			client.addPerson();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			client.exitMenu();
			return 0;
			break;
		}
	}
	



	system("pause");

	return 0;
}