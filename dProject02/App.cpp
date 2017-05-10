#include "App.h"
#include <iostream>
#include <string>
using namespace std;

App::App(){
	users_length = 0;
	stores_length = 0;
	locations_length = 0;

	loginedUser = NULL;
	load_users();
}
App::~App(){
	save_users();
}

void App::run() {
	int command;
	while (1) {
		cout << endl;
		cout << "##############################" << endl;
		cout << "#######     �α���     #######" << endl;
		cout << "##############################" << endl;
		cout << "1. �� �α���" << endl;
		cout << "2. ������ �α���" << endl;
		cout << "3. �α׾ƿ�" << endl;
		cout << "0. ����" << endl;
		cout << "choose command -> ";
		cin >> command;

		switch (command) {
		case 1:
			if (loginedUser != NULL) {
				if (loginedUser->getUserType() == CLIENT) {
					cout << "�α��� �Ǿ����ϴ�." << endl;
					clientMenu();
				}
				else {
					if (clientLogin())
						clientMenu();
				}
			}				
			else
				if (clientLogin())
					clientMenu();
			break;
		case 2:
			if (loginedUser != NULL) {
				if (loginedUser->getUserType() == MANAGER) {
					cout << "�α��� �Ǿ����ϴ�." << endl;
					managerMenu();
				}
				else {
					if (managerLogin())
						managerMenu();
				}
			}
			else
				if (managerLogin())
					managerMenu();
			break;
		case 3:
			if (loginedUser != NULL) {
				loginedUser = NULL; // ��ü ������ ����
				cout << "�α׾ƿ� �Ǿ����ϴ�." << endl;
			}
			else {
				cout << "�α����� ������ �����ϴ�." << endl;
			}
			break;
		case 0:
			return;
		default :
			cout << "�߸��� ��ɾ��Դϴ�." << endl;
			break;
		}
	}
}

// �α��� ���
bool App::clientLogin() {
	string id, password;
	cout << endl << "#######   �� �α���  #######" << endl;
	cout << "ID	:";
	cin >> id;
	cout << "PW	:";
	cin >> password;

	list<User*>::iterator iter;
	for (iter = users.begin(); iter != users.end(); iter++) {
		if ((*iter)->checkUserInfo(id, password, CLIENT) == true) {
			loginedUser = *iter; // Client �������� ����
			return true;
		}

		cout << "���̵� Ȥ�� ��й�ȣ�� �߸��Ǿ����ϴ�." << endl;
		return false;
	}
}
bool App::managerLogin() {
	string id, password;
	cout << endl << "#######  ������ �α��� #######" << endl;
	cout << "ID	:";
	cin >> id;
	cout << "PW	:";
	cin >> password;

	list<User*>::iterator iter;
	for (iter = users.begin(); iter != users.end(); iter++) {
		if ((*iter)->checkUserInfo(id, password, MANAGER)) {
			loginedUser = *iter; // Manager �������� ����
			return true;
		}

		cout << "���̵� Ȥ�� ��й�ȣ�� �߸��Ǿ����ϴ�." << endl;
		return false;
	}
}

// ��
// ����ȭ��
void App::clientMenu() {
	int command;
	while (1) {
		cout << endl;
		cout << "##############################" << endl;
		cout << "#######   �� �޴�    #######" << endl;
		cout << "##############################" << endl;
		loginedUser->printInfo();
		cout << "##############################" << endl;
		cout << "1. ������ �̸��� �˻�" << endl;
		cout << "2. ������ ������ �˻�" << endl;
		cout << "3. ��ġ ���� ����" << endl;
		cout << "0. �ڷΰ���" << endl;
		cout << "choose command -> ";
		cin >> command;

		switch (command) {
		case 1:
			findStoreByName();
			break;
		case 2:
			findStoreByCategory();
			break;
		case 3:
			changeMyLocation();
			break;
		case 0:
			return;
		default:
			cout << "�߸��� ��ɾ��Դϴ�." << endl;
			break;
		}
	}
}

void App::findStoreByName() {
	string name;
	cout << endl << "########  ������ �˻�  #######" << endl;
	cout << "�̸�(Ű����)�� �Է��ϼ��� : ";
	cin >> name;

	//command : ����� �Է�, count : ���� ��� ī����
	int command, count = 0;
	list<bool> check;
	list<Store*>::iterator iter;
	for (iter = stores.begin(); iter != stores.end(); iter++) {
		string storeName = (*iter)->getStoreName;
		if (storeName.find(name)!= string::npos) {
			count++;
			cout << count << ". " << storeName << endl;
			check.push_back(true); //check�� ���°���� �̸��� ã�Ҵ��� ����
		}
		else {
			check.push_back(false);
		}
	}
	cout << "0. �ڷΰ���" << endl;
	cout << "##############################" << endl;
	cout << "choose -> ";
	cin >> command;

	if (command == 0)
		return;
	else if (0 < command && command <= count) {
		int index = 0;
		list<bool>::iterator tempCheck;
		list<Store*>::iterator tempStore;
		tempCheck = check.begin();
		for (tempStore = stores.begin(); tempStore != stores.end(); tempStore++) {
			//tempCheck�� true�� index�� ����
			if (*tempCheck)
				index++;

			if (index == command) {
				orderFood(*tempStore); // �ֹ�â���� �Ѿ��
				break;
			}

			tempCheck++;
		}
	}
	else
		cout << "�߸��� ����Դϴ�." << endl;
}

void App::findStoreByCategory() {
	string name;
	cout << endl << "########  ������ �˻�  #######" << endl;
	cout << "������ ����(Ű����)�� �Է��ϼ��� : ";
	cin >> name;

	//command : ����� �Է�, count : ���� ��� ī����
	int command, count = 0;
	list<bool> check;
	list<Store*>::iterator iter;
	for (iter = stores.begin(); iter != stores.end(); iter++) {
		string storeType = (*iter)->getStoreType();
		if (storeType.find(name) != string::npos) {
			count++;
			cout << count << ". " << storeType << endl;
			check.push_back(true); //check�� ���°���� �̸��� ã�Ҵ��� ����
		}
		else {
			check.push_back(false);
		}
	}
	cout << "0. �ڷΰ���" << endl;
	cout << "##############################" << endl;
	cout << "choose -> ";
	cin >> command;

	if (command == 0)
		return;
	else if (0 < command && command <= count) {
		int index = 0;
		list<bool>::iterator tempCheck;
		list<Store*>::iterator tempStore;
		tempCheck = check.begin();
		for (tempStore = stores.begin(); tempStore != stores.end(); tempStore++) {
			//tempCheck�� true�� index�� ����
			if (*tempCheck)
				index++;

			if (index == command) {
				orderFood(*tempStore); // �ֹ�â���� �Ѿ��
				break;
			}

			tempCheck++;
		}
	}
	else
		cout << "�߸��� ����Դϴ�." << endl;
}

void App::changeMyLocation() {

}

void App::orderFood(Store* store) {
	cout << endl << "���õ� ������: " << store->getStoreName() << endl;
	cout << "##############################" << endl;
	store->addOrder(); //�ֹ��ϱ�
	cout << "�ֹ��� �Ϸ�Ǿ����ϴ� :)" << endl;
	cout << "���� ��޽ð��� " << "�� �Դϴ�." << endl;
}

// ������
// ����ȭ��
void App::managerMenu() {
	int command;
	while (1) {
		cout << endl;
		cout << "##############################" << endl;
		cout << "#######   ������ �޴�  #######" << endl;
		cout << "##############################" << endl;
		loginedUser->printInfo();
		cout << "##############################" << endl;
		cout << "1. �ֹ� ��� Ȯ��" << endl;
		cout << "2. ��� ���� �Ÿ� ����" << endl;
		cout << "0. �ڷΰ���" << endl;
		cout << "choose command -> ";
		cin >> command;

		switch (command) {
		case 1:
			showOrderList();
			break;
		case 2:
			changeRadius();
			break;
		case 0:
			return;
		default:
			cout << "�߸��� ��ɾ��Դϴ�." << endl;
			break;
		}
	}
}

void App::showOrderList() {

}

void App::changeRadius() {

}

void App::load_users() {
	ifstream fin("user.txt");
	string record;

	string id, password, name;
	int userType, locationId;

	while (!fin.eof()) {
		getline(fin, record);
		stringstream iss(record);

		iss >> id >> password >> name >> userType >> locationId;
		User *user;
		if (userType == CLIENT)
			user = new Client;
		else
			user = new Manager;

		user->setID(id);
		user->setPassword(password);
		user->setName(name);
		user->setUserType(userType);
		user->setLocationID(locationId);

		users.push_back(user);
		users_length++;
	}

	fin.close();
}

void App::save_users() {
	ofstream fout("user.txt");
	ostringstream ssOut;

	list<User*>::iterator iter;
	for (iter = users.begin(); iter != users.end(); iter++) {
		ssOut << (*iter)->getID() << " " << (*iter)->getPassword()
			<< " " << (*iter)->getName() << " " << (*iter)->getUserType() << " " << (*iter)->getLocationID() << endl;
	}
	fout << ssOut.str();

	fout.close();
}