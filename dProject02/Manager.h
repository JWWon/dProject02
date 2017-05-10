#include "User.h"
#pragma once
class Manager :	public User
{
public:
	Manager() {}
	~Manager() {}

	//가상함수 GETTER SETTER
	virtual void printInfo();
};