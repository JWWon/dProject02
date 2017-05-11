#include "App.h"
#include <iostream>
#include <string>
using namespace std;

App::App(){
	users_length = 0;
	stores_length = 0;
	locations_length = 0;

	loginedUser = NULL;
	load_user_file();
	load_store_file();
	load_location_file();
}
App::~App(){
	//save_user_file();
}

void App::run() {
	int command;
	while (1) {
		cout << endl;
		cout << "##############################" << endl;
		cout << "#######     로그인     #######" << endl;
		cout << "##############################" << endl;
		cout << "1. 고객 로그인" << endl;
		cout << "2. 관리자 로그인" << endl;
		cout << "3. 로그아웃" << endl;
		cout << "0. 종료" << endl;
		cout << "choose command -> ";
		cin >> command;

		switch (command) {
		case 1:
			if (loginedUser != NULL) {
				if (loginedUser->getUserType() == CLIENT) {
					cout << "로그인 되었습니다." << endl;
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
					cout << "로그인 되었습니다." << endl;
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
				loginedUser = NULL; // 객체 포인터 삭제
				cout << "로그아웃 되었습니다." << endl;
			}
			else {
				cout << "로그인한 정보가 없습니다." << endl;
			}
			break;
		case 0:
			return;
		default :
			cout << "잘못된 명령어입니다." << endl;
			break;
		}
	}
}

// 로그인 기능
bool App::clientLogin() {
	string id, password;
	cout << endl << "#######   고객 로그인  #######" << endl;
	cout << "ID	:";
	cin >> id;
	cout << "PW	:";
	cin >> password;

	list<User*>::iterator iter;
	for (iter = users.begin(); iter != users.end(); iter++) {
		if ((*iter)->checkUserInfo(id, password, CLIENT) == true) {
			loginedUser = *iter; // Client 내용으로 정의
			return true;
		}
	}

	cout << "아이디 혹은 비밀번호가 잘못되었습니다." << endl;
	return false;
}
bool App::managerLogin() {
	string id, password;
	cout << endl << "#######  관리자 로그인 #######" << endl;
	cout << "ID	:";
	cin >> id;
	cout << "PW	:";
	cin >> password;

	list<User*>::iterator iter;
	for (iter = users.begin(); iter != users.end(); iter++) {
		if ((*iter)->checkUserInfo(id, password, MANAGER)) {
			loginedUser = *iter; // Manager 내용으로 정의
			return true;
		}
	}

	cout << "아이디 혹은 비밀번호가 잘못되었습니다." << endl;
	return false;
}

// 고객
// 메인화면
void App::clientMenu() {
	int command;
	while (1) {
		cout << endl;
		cout << "##############################" << endl;
		cout << "#######   고객 메뉴    #######" << endl;
		cout << "##############################" << endl;
		loginedUser->printInfo();
		cout << "##############################" << endl;
		cout << "1. 음식점 이름을 검색" << endl;
		cout << "2. 음식점 종류로 검색" << endl;
		cout << "3. 위치 정보 변경" << endl;
		cout << "0. 뒤로가기" << endl;
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
			cout << "잘못된 명령어입니다." << endl;
			break;
		}
	}
}

void App::findStoreByName() {
	string name;
	cout << endl << "########  음식점 검색  #######" << endl;
	cout << "이름(키워드)를 입력하세요 : ";
	cin >> name;

	//command : 사용자 입력, count : 가게 목록 카운팅
	int command, count = 0;
	list<bool> check;
	list<Store*>::iterator iter;
	for (iter = stores.begin(); iter != stores.end(); iter++) {
		string storeName = (*iter)->getStoreName();
		if (storeName.find(name)!= string::npos) {
			count++;
			cout << count << ". " << storeName << endl;
			check.push_back(true); //check로 몇번째에서 이름을 찾았는지 저장
		}
		else {
			check.push_back(false);
		}
	}
	cout << "0. 뒤로가기" << endl;
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
			//tempCheck가 true면 index를 증가
			if (*tempCheck)
				index++;

			if (index == command) {
				orderFood(*tempStore); // 주문창으로 넘어가기
				break;
			}

			tempCheck++;
		}
	}
	else
		cout << "잘못된 명령입니다." << endl;
}

void App::findStoreByCategory() {
	string name;
	cout << endl << "########  음식점 검색  #######" << endl;
	cout << "음식점 종류(키워드)를 입력하세요 : ";
	cin >> name;

	//command : 사용자 입력, count : 가게 목록 카운팅
	int command, count = 0;
	list<bool> check;
	list<Store*>::iterator iter;
	for (iter = stores.begin(); iter != stores.end(); iter++) {
		string storeType = (*iter)->getStoreType();
		if (storeType.find(name) != string::npos) {
			count++;
			cout << count << ". " << storeType << endl;
			check.push_back(true); //check로 몇번째에서 이름을 찾았는지 저장
		}
		else {
			check.push_back(false);
		}
	}
	cout << "0. 뒤로가기" << endl;
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
			//tempCheck가 true면 index를 증가
			if (*tempCheck)
				index++;

			if (index == command) {
				orderFood(*tempStore); // 주문창으로 넘어가기
				break;
			}

			tempCheck++;
		}
	}
	else
		cout << "잘못된 명령입니다." << endl;
}

void App::changeMyLocation() {

}

void App::orderFood(Store* store) {
	cout << endl << "선택된 음식점: " << store->getStoreName() << endl;
	cout << "##############################" << endl;
	store->addOrder(); //주문하기
	cout << "주문이 완료되었습니다 :)" << endl;
	cout << "예상 배달시간은 " << store->calculateDeliverTime(1,1,1,1) <<"분 입니다." << endl; //TODO: calcDelieverTime 수정
}

// 관리자
// 메인화면
void App::managerMenu() {
	int command;
	while (1) {
		cout << endl;
		cout << "##############################" << endl;
		cout << "#######   관리자 메뉴  #######" << endl;
		cout << "##############################" << endl;
		loginedUser->printInfo();
		cout << "##############################" << endl;
		cout << "1. 주문 목록 확인" << endl;
		cout << "2. 배달 가능 거리 변경" << endl;
		cout << "0. 뒤로가기" << endl;
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
			cout << "잘못된 명령어입니다." << endl;
			break;
		}
	}
}

void App::showOrderList() {

}

void App::changeRadius() {

}

void App::load_user_file() {
	ifstream fin("user.txt");
	string record;

	int userType;
	string id, password;
	//Client
	string name;
	int locationId;
	//Manager
	int storeId;

	while (!fin.eof()) {
		getline(fin, record);
		stringstream iss(record);

		iss >> userType;
		User *user;
		if (userType == CLIENT) {
			user = new Client;
			iss >> id >> password >> name >> locationId;

			user->setUserType(userType);
			user->setID(id);
			user->setPassword(password);
			user->setName(name);
			user->setLocationID(locationId);
		}
		else {
			user = new Manager;
			iss >> id >> password >> storeId; //TODO: + 음식점 ID

			user->setUserType(userType);
			user->setID(id);
			user->setPassword(password);
			user->setStoreID(storeId);
		}

		users.push_back(user);
		users_length++;
	}

	fin.close();
}

void App::load_store_file() {
	ifstream fin("store.txt");
	string record;

	int storeID;
	string storeName, storeType;
	int availableDistance;
	while (!fin.eof()) {
		getline(fin, record);
		stringstream iss(record);

		iss >> storeID >> storeName >> storeType >> availableDistance;
		Store *store;
		if (storeName == "한식집") {
			store = new Korean;
		}
		else {
			store = new Chinese;
		}

		store->setStoreID(storeID);
		store->setStoreName(storeName);
		store->setStoreType(storeType);
		store->setDistance(availableDistance);

		stores.push_back(store);
		stores_length++;
	}

	fin.close();
}

void App::load_location_file() {
	ifstream fin("location.txt");
	string record;

	//userType에 따라 id가 독립적이다!
	int id, userType, latitude, longitude;
	while (!fin.eof()) {
		getline(fin, record);
		stringstream iss(record);

		iss >> id >> userType >> latitude >> longitude;
		Location* location = new Location;
		location->locationId = id;
		location->locationType = userType;
		location->latitude = latitude;
		location->longitude = longitude;

		locations.push_back(location);
		locations_length++;
	}

	fin.close();
}

void App::save_user_file() {
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