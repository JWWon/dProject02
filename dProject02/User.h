#pragma once
#include <iostream>
#include <string>
enum user_type {CLIENT, MANAGER};
using namespace std;

class User {
public:
	User();
	~User();
	// 로그인 시 정보 비교
	bool checkUserInfo(string k_id, string k_password, int k_userType);

	//GETTER SETTER
	void setID(string k_id) { id = k_id; }
	string getID() { return id; }

	void setPassword(string k_password) { password = k_password; }
	string getPassword() { return password; }

	void setUserType(int k_userType) { userType = k_userType; }
	int getUserType() { return userType; }
	//END

	//가상함수 GETTER SETTER
	virtual void printInfo() = 0;

	//Client
	virtual void setName(string k_name) = 0;
	virtual string getName() = 0;

	virtual void setLocationID(int k_locID) = 0;
	virtual int getLocationID() = 0;

	//Manager
	virtual void setStoreID(int k_storeID) = 0;
	virtual int getStoreID() = 0;
	//END

protected:
	string id;
	string password;
	int userType; // 사용자 종류
	
};