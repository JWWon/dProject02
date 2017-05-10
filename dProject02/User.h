#pragma once
#include <iostream>
#include <string>
enum user_type {CLIENT, MANAGER};
using namespace std;

class User {
public:
	User();
	~User();
	// �α��� �� ���� ��
	bool checkUserInfo(string k_id, string k_password, int k_userType);

	//GETTER SETTER
	void setID(string k_id) { id = k_id; }
	string getID() { return id; }

	void setPassword(string k_password) { password = k_password; }
	string getPassword() { return password; }

	void setUserType(int k_userType) { userType = k_userType; }
	int getUserType() { return userType; }

	void setName(string k_name) { userName = k_name; }
	string getName() { return userName; }

	void setLocationID(int k_locID) { locationId = k_locID; }
	int getLocationID() { return locationId; }
	//END

	//�����Լ� GETTER SETTER
	virtual void printInfo() = 0;
	//END

protected:
	string id;
	string password;
	string userName;
	int userType; // ����� ����
	int locationId;
};