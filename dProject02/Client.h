#pragma once
#include "User.h"
class Client : public User
{
public:
	Client() {}
	~Client() {}

	//�����Լ� GETTER SETTER
	virtual void printInfo();
};