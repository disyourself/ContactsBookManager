
#include<iostream>	
#include<string>

#define MAX 1000

using namespace std;

//��ϵ�˽ṹ��
struct Person 
{
	string name;
	int sex; //1�� 2Ů
	int age;
	string address;
	string phoneNumber;
};

//ͨѶ¼�ṹ��
struct _contactBooks {
	struct Person personArray[MAX];		//����Peroson struct
	int size;
};





void showMenu() {
	cout << "*****************************" << endl;
	cout << "*****	1�������ϵ��	*****" << endl;
	cout << "*****	2����ʾ��ϵ��	*****" << endl;
	cout << "*****	3��ɾ����ϵ��	*****" << endl;
	cout << "*****	4��������ϵ��	*****" << endl;
	cout << "*****	5���޸���ϵ��	*****" << endl;
	cout << "***	6���������ϵ��" << "	  ***" << endl;
	cout << "*****	0���˳�ͨѶ¼	*****" << endl;
	cout << "*****************************" << endl;
}

void addPerson(_contactBooks* contactBooks) {
	if (contactBooks->size == MAX) {
		cout << "ͨѶ¼����" << endl;
		return;
	}

	//����
	string _name;
	cout << "a.����������" << endl;
	cin >> _name;
	contactBooks->personArray[contactBooks->size].name = _name;
	//�Ա�
	cout << "b.�������Ա�" << endl;
	cout << "1-�С�2-Ů" << endl;
	int sex = 0;
	while (1) {
		cin >> sex;
		if (sex == 1 || sex == 2) {
			contactBooks->personArray[contactBooks->size].sex = sex;
			break;
		}
		cout << "�������,����������" << endl;
	}
	//����
	cout << "c.���������䣺\n";
	int age = 0;
	cin >> age;
	contactBooks->personArray[contactBooks->size].age = age;
	//�绰
	cout << "d.������绰���룺\n";
	string Number;
	cin >> Number;
	contactBooks->personArray[contactBooks->size].phoneNumber = Number;
	//סַ
	cout << "e.������סַ��\n";
	string addres;
	cin >> addres;
	contactBooks->personArray[contactBooks->size].address = addres;

	//����ͨѶ¼����
	contactBooks->size++;

	cout << "��ӳɹ�!\n";
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ�������ϵ�������еľ���λ�ã�����-1
//����1 contacbooksarray ����2 �Ա�����
int isExist(_contactBooks* contactBooks, string name) {
	for (int i = 0; i < contactBooks->size; i++) {
		if (contactBooks->personArray[i].name == name) {
			return i;
		}
	}
	return -1;
}

//��ʾ������ϵ����Ϣ
void showPerson(_contactBooks *contactBooks,int ret) {
	cout << "������ " << contactBooks->personArray[ret].name << "\t";
	cout << "�Ա� " << (contactBooks->personArray[ret].sex == 1 ? "��" : "Ů") << "\t";
	cout << "���䣺 " << contactBooks->personArray[ret].age << "\t";
	cout << "�绰�� " << contactBooks->personArray[ret].phoneNumber << "\t";
	cout << "סַ�� " << contactBooks->personArray[ret].address << endl;
}


void showContactBooks(_contactBooks *contactBooks) {
	if (contactBooks->personArray == 0) {
		cout << "��ǰ��¼Ϊ��\n";
	}
	for (int i = 0; i < contactBooks->size; i++) {
		cout << "������ " << contactBooks->personArray[i].name << "\t";
		cout << "�Ա� " << (contactBooks->personArray[i].sex == 1 ? "��" : "Ů")<<"\t";
		cout << "���䣺 " << contactBooks->personArray[i].age << "\t";
		cout << "�绰�� " << contactBooks->personArray[i].phoneNumber << "\t";
		cout << "סַ�� " << contactBooks->personArray[i].address<< endl;
	}
	system("pause");
	system("cls");
}
void deletePerson(_contactBooks* contactBooks) {
	cout << "��������Ҫɾ������ϵ��\n";
	string name;
	cin >> name;
	int ret = isExist(contactBooks, name);
	if (ret == -1) {
		cout << "���޴���\n";
	}
	//ɾ�������������ĺ������ַǰ��һλ
	for (int i = ret; i < contactBooks->size; i++) {
		//����ǰ��
		contactBooks->personArray[i] = contactBooks->personArray[i + 1];
	}
	//���³�Ա
	contactBooks->size--;
	cout << "ɾ���ɹ�\n";
	system("pause");
	system("cls");
}

void findPerson(_contactBooks* contactBooks) {
	cout << "��������Ҫ���ҵ���ϵ��\n";
	string name;
	cin >> name;

	int ret = isExist(contactBooks, name);
	if (ret == -1) {
		cout << "δ�ҵ���ϵ��\n";
	}	
	cout << "������ " << contactBooks->personArray[ret].name << "\t";
	cout << "�Ա� " << (contactBooks->personArray[ret].sex == 1 ? "��" : "Ů") << "\t";
	cout << "���䣺 " << contactBooks->personArray[ret].age << "\t";
	cout << "�绰�� " << contactBooks->personArray[ret].phoneNumber << "\t";
	cout << "סַ�� " << contactBooks->personArray[ret].address << endl;

	system("pause");
	system("cls");
}

void modifyPerson(_contactBooks *contactBooks) {
	cout << "������Ҫ�޸ĵ���ϵ��\n";
	string name;
	cin >> name;
	int ret = isExist(contactBooks, name);
	int number=0;
	if (ret == -1) {
		cout << "δ�ҵ�ָ����ϵ��\n";
	}
	while (1) {
		showPerson(contactBooks, ret);
		cout << "��ѡ��Ҫ�޸ĵ�����˳�򣨴���Ϊ1++��:" << endl;
		cout << "����0ȡ���޸�\n";
		int number;
		cin>>number;
	

		switch (number)
		{
		case 1: {
			cout << "�������޸ĺ��������\n";
			string name;
			cin >> name;
			contactBooks->personArray[ret].name = name;
			break; }
		case 2: {
			cout << "�������޸ĺ���Ա�1�С�2Ů\n";
			int sex;
			cin >> sex;
			if (sex != 1 && sex != 2) {
				cout << "�������1���� 2��Ů��\n";
				system("pause");
				system("cls");
				return;
			}
			contactBooks->personArray[ret].sex = sex; 
			break; }
		case 3: {
			cout << "�������޸ĺ�����䣺\n";
			int age;
			cin >> age;
			contactBooks->personArray[ret].age = age;
			break; }
		case 4: {
			cout << "�������޸ĺ�ĵ绰��\n";
			string pohoneNumber;
			cin >> pohoneNumber;
			contactBooks->personArray[ret].phoneNumber = pohoneNumber;
			break; }
		case 5: {
			cout << "�������޸ĺ��סַ��\n";
			string adress;
			cin >> adress;
			contactBooks->personArray[ret].address = adress;
			break; }
		case 0: {
			return;
			break; }
		}
		cout << "�޸ĳɹ�\n";
		return;
	}
	system("pause");
	system("cls");
}



void exitMenu() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
}




int main() {
	_contactBooks contactBooks;
	contactBooks.size = 0;


	
	
	int select = 0;

	while (1) {
		showMenu();
		cout << "����ָ�" << endl;
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