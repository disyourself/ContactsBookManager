
#include<iostream>	
#include<iomanip>
#include"ͨѶ¼.h"

using namespace std;


int main() {
	ͨѶ¼ client;
	client.showMenu();
	
	int select = 0;

	while (1) {
		cout << "����ָ�" << endl;
		cin >> select;

		if (select < 0 && select>6) {
			cout << "����ָ�����" << endl;
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