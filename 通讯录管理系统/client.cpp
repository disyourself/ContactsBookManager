
#include<iostream>	
#include<string>

#define MAX 1000

using namespace std;

//联系人结构体
struct Person 
{
	string name;
	int sex; //1男 2女
	int age;
	string address;
	string phoneNumber;
};

//通讯录结构体
struct _contactBooks {
	struct Person personArray[MAX];		//包含Peroson struct
	int size;
};





void showMenu() {
	cout << "*****************************" << endl;
	cout << "*****	1、添加联系人	*****" << endl;
	cout << "*****	2、显示联系人	*****" << endl;
	cout << "*****	3、删除联系人	*****" << endl;
	cout << "*****	4、查找联系人	*****" << endl;
	cout << "*****	5、修改联系人	*****" << endl;
	cout << "***	6、清空联联系人" << "	  ***" << endl;
	cout << "*****	0、退出通讯录	*****" << endl;
	cout << "*****************************" << endl;
}

void addPerson(_contactBooks* contactBooks) {
	if (contactBooks->size == MAX) {
		cout << "通讯录已满" << endl;
		return;
	}

	//姓名
	string _name;
	cout << "a.请输入姓名" << endl;
	cin >> _name;
	contactBooks->personArray[contactBooks->size].name = _name;
	//性别
	cout << "b.请输入性别：" << endl;
	cout << "1-男、2-女" << endl;
	int sex = 0;
	while (1) {
		cin >> sex;
		if (sex == 1 || sex == 2) {
			contactBooks->personArray[contactBooks->size].sex = sex;
			break;
		}
		cout << "输入错误,请重新输入" << endl;
	}
	//年龄
	cout << "c.请输入年龄：\n";
	int age = 0;
	cin >> age;
	contactBooks->personArray[contactBooks->size].age = age;
	//电话
	cout << "d.请输入电话号码：\n";
	string Number;
	cin >> Number;
	contactBooks->personArray[contactBooks->size].phoneNumber = Number;
	//住址
	cout << "e.请输入住址：\n";
	string addres;
	cin >> addres;
	contactBooks->personArray[contactBooks->size].address = addres;

	//更新通讯录人数
	contactBooks->size++;

	cout << "添加成功!\n";
	system("pause");
	system("cls");
}

//检测联系人是否存在？返回联系人数组中的具体位置：返回-1
//参数1 contacbooksarray 参数2 对比姓名
int isExist(_contactBooks* contactBooks, string name) {
	for (int i = 0; i < contactBooks->size; i++) {
		if (contactBooks->personArray[i].name == name) {
			return i;
		}
	}
	return -1;
}

//显示单个联系人信息
void showPerson(_contactBooks *contactBooks,int ret) {
	cout << "姓名： " << contactBooks->personArray[ret].name << "\t";
	cout << "性别： " << (contactBooks->personArray[ret].sex == 1 ? "男" : "女") << "\t";
	cout << "年龄： " << contactBooks->personArray[ret].age << "\t";
	cout << "电话： " << contactBooks->personArray[ret].phoneNumber << "\t";
	cout << "住址： " << contactBooks->personArray[ret].address << endl;
}


void showContactBooks(_contactBooks *contactBooks) {
	if (contactBooks->personArray == 0) {
		cout << "当前记录为空\n";
	}
	for (int i = 0; i < contactBooks->size; i++) {
		cout << "姓名： " << contactBooks->personArray[i].name << "\t";
		cout << "性别： " << (contactBooks->personArray[i].sex == 1 ? "男" : "女")<<"\t";
		cout << "年龄： " << contactBooks->personArray[i].age << "\t";
		cout << "电话： " << contactBooks->personArray[i].phoneNumber << "\t";
		cout << "住址： " << contactBooks->personArray[i].address<< endl;
	}
	system("pause");
	system("cls");
}
void deletePerson(_contactBooks* contactBooks) {
	cout << "请输入你要删除的联系人\n";
	string name;
	cin >> name;
	int ret = isExist(contactBooks, name);
	if (ret == -1) {
		cout << "查无此人\n";
	}
	//删除张三，将李四和王五地址前移一位
	for (int i = ret; i < contactBooks->size; i++) {
		//数据前移
		contactBooks->personArray[i] = contactBooks->personArray[i + 1];
	}
	//更新成员
	contactBooks->size--;
	cout << "删除成功\n";
	system("pause");
	system("cls");
}

void findPerson(_contactBooks* contactBooks) {
	cout << "请输入您要查找的联系人\n";
	string name;
	cin >> name;

	int ret = isExist(contactBooks, name);
	if (ret == -1) {
		cout << "未找到联系人\n";
	}	
	cout << "姓名： " << contactBooks->personArray[ret].name << "\t";
	cout << "性别： " << (contactBooks->personArray[ret].sex == 1 ? "男" : "女") << "\t";
	cout << "年龄： " << contactBooks->personArray[ret].age << "\t";
	cout << "电话： " << contactBooks->personArray[ret].phoneNumber << "\t";
	cout << "住址： " << contactBooks->personArray[ret].address << endl;

	system("pause");
	system("cls");
}

void modifyPerson(_contactBooks *contactBooks) {
	cout << "请输入要修改的联系人\n";
	string name;
	cin >> name;
	int ret = isExist(contactBooks, name);
	int number=0;
	if (ret == -1) {
		cout << "未找到指定联系人\n";
	}
	while (1) {
		showPerson(contactBooks, ret);
		cout << "请选择要修改的数据顺序（从左为1++）:" << endl;
		cout << "输入0取消修改\n";
		int number;
		cin>>number;
	

		switch (number)
		{
		case 1: {
			cout << "请输入修改后的姓名：\n";
			string name;
			cin >> name;
			contactBooks->personArray[ret].name = name;
			break; }
		case 2: {
			cout << "请输入修改后的性别：1男、2女\n";
			int sex;
			cin >> sex;
			if (sex != 1 && sex != 2) {
				cout << "输入错误（1、男 2、女）\n";
				system("pause");
				system("cls");
				return;
			}
			contactBooks->personArray[ret].sex = sex; 
			break; }
		case 3: {
			cout << "请输入修改后的年龄：\n";
			int age;
			cin >> age;
			contactBooks->personArray[ret].age = age;
			break; }
		case 4: {
			cout << "请输入修改后的电话：\n";
			string pohoneNumber;
			cin >> pohoneNumber;
			contactBooks->personArray[ret].phoneNumber = pohoneNumber;
			break; }
		case 5: {
			cout << "请输入修改后的住址：\n";
			string adress;
			cin >> adress;
			contactBooks->personArray[ret].address = adress;
			break; }
		case 0: {
			return;
			break; }
		}
		cout << "修改成功\n";
		return;
	}
	system("pause");
	system("cls");
}



void exitMenu() {
	cout << "欢迎下次使用" << endl;
	system("pause");
}




int main() {
	_contactBooks contactBooks;
	contactBooks.size = 0;


	
	
	int select = 0;

	while (1) {
		showMenu();
		cout << "输入指令：" << endl;
		cin >> select;

		switch (select)
		{
		case 1:
			addPerson(&contactBooks);
			break;
		case 2:
			showContactBooks(&contactBooks);
			break;
		case 3:
			deletePerson(&contactBooks);
			break;
		case 4:findPerson(&contactBooks);
			break;
		case 5:modifyPerson(&contactBooks);
			break;
		case 6:
			break;
		case 0:
			exitMenu();
			return 0;
			break;
		}
	}
	



	system("pause");

	return 0;
}