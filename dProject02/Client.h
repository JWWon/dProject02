#pragma once
#include "User.h"
class Client : public User
{
public:
	Client() {}
	~Client() {}

	//가상함수 GETTER SETTER
	virtual void printInfo();
};